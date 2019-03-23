#ifndef _LOG_
#define _LOG_

#include "Ilog.h"
#include <string>

class Log :public Ilog
{
public:
	enum MyEnum
	{
		ERROR_LEVEL,
		WARN_LEVEL,
		INFO_LEVE
	};

	static Log* pLogInstance;
public:
	Log();

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

	const unsigned int m_StoreFileSize = 1024 * 1024 * 5;

};

#endif