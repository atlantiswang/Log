#include "log.h"
#include <sys/stat.h>

Log* Log::pLogInstance = NULL;

Log* Log::LogInstance()
{
	if (Log::pLogInstance == NULL)
	{
		Log::pLogInstance = new Log;
	}
	return Log::pLogInstance;
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

Log::Log()
{
	m_logfile = "test.txt";
}



bool Log::WriteLog(const char* szLog, unsigned int nLevel)
{
	bool bRet = false;
	//写日志前的准备： 1判断当前文件大小是否超过保存量，2如果超过就备份为 m_logfile.bak(如果已经有了些文件就删除) 并创建一个新的文件m_logfile 3如果不超过就使用现在的
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
	fwrite(m_strLogInfo.c_str(), 1, m_strLogInfo.size(), fp);
	fclose(fp);

	return bRet;
}
