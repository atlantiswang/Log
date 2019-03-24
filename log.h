#ifndef _LOG_H_
#define _LOG_H_

#include "Ilog.h"
#include <string>
#include <windows.h>

class Lock;

class Log :public Ilog
{
private:
	enum MyEnum
	{
		ERROR_LEVEL,
		WARN_LEVEL,
		INFO_LEVE
	};

	class MutexHolder
	{
	public:
		MutexHolder(Lock& lk);

		~MutexHolder();

	private:
		Lock& m_lk;
	};

public:
	Log();

	~Log();

	virtual bool WriteErrorLog(const char* szLog);

	virtual bool WriteWarnLog(const char* szLog);

	virtual bool WriteInfoLog(const char* szLog);

	static Log* LogInstance();

private:
	virtual bool WriteLog(const char* szLog, unsigned int nLevel);

	void WriteLogPre();

private:
	std::string m_logfile;

	std::string m_strLogInfo;

	static Log* m_pLogInstance;

	const unsigned int m_StoreFileSize;
};

#endif