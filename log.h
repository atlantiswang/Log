#ifndef _LOG_H_
#define _LOG_H_

#include "Ilog.h"
#include <string>
#include <windows.h>
#include "lock.h"

class Log :public Ilog
{
public:
	enum MyEnum
	{
		ERROR_LEVEL,
		WARN_LEVEL,
		INFO_LEVE
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

	const unsigned int m_StoreFileSize = 1024 * 1024 * 5;

	ILock * m_pLock;
};

#endif