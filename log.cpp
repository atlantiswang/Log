#include "log.h"
#include <sys/stat.h>
#include "lock.h"

Log* Log::m_pLogInstance = NULL;

Log* Log::LogInstance()
{
	if (m_pLogInstance == NULL)
	{
		m_pLogInstance = new Log;
	}
	return m_pLogInstance;
}

bool Log::WriteErrorLog(const char* szLog)
{
	return WriteLog(szLog, ERROR_LEVEL);
}

bool Log::WriteWarnLog(const char* szLog)
{
	return WriteLog(szLog, WARN_LEVEL);
}

bool Log::WriteInfoLog(const char* szLog)
{
	return WriteLog(szLog, INFO_LEVE);
}

void Log::WriteLogPre()
{
	struct stat buff;
	stat(m_logfile.c_str(), &buff);
	if (buff.st_size >= m_StoreFileSize)
	{
		std::string strBakFileName = m_logfile + ".bak";

		remove(strBakFileName.c_str());
		rename(m_logfile.c_str(), strBakFileName.c_str());
	}
}

Log::Log():
	m_StoreFileSize(1024*1024*5)
{
	m_logfile = "test.txt";
}

Log::~Log()
{
}

Log::MutexHolder::MutexHolder(Lock &lk)
	:m_lk(lk)
{
	m_lk.LockWork();
}

Log::MutexHolder::~MutexHolder()
{
	m_lk.UnLock();
}


bool Log::WriteLog(const char* szLog, unsigned int nLevel)
{
	static Lock lock;
	MutexHolder locker(lock);
	bool bRet = true;
	//д��־ǰ��׼���� 1�жϵ�ǰ�ļ���С�Ƿ񳬹���������2��������ͱ���Ϊ m_logfile.bak(����Ѿ�����Щ�ļ���ɾ��) ������һ���µ��ļ�m_logfile 3�����������ʹ�����ڵ�
	WriteLogPre();

	if (nLevel == ERROR_LEVEL)
	{
		m_strLogInfo = "ERROR:";
	}
	else if (nLevel == WARN_LEVEL)
	{
		m_strLogInfo = "WARNING:";
	}
	else if (nLevel == INFO_LEVE)
	{
		m_strLogInfo = "INFO:";
	}

	m_strLogInfo += szLog;
	m_strLogInfo += "\r\n";

	FILE *fp = NULL;
	fopen_s(&fp, m_logfile.c_str(), "a");
	if (fp != NULL)
	{
		fwrite(m_strLogInfo.c_str(), 1, m_strLogInfo.size(), fp);
		fclose(fp);
		fp = NULL;
	}
	else
	{
		bRet = false;
	}

	return bRet;
}
