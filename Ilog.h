#ifndef	_I_LOG_
#define _I_LOG_

class Ilog
{
public:
	virtual bool WriteErrorLog(const char* szLog) = 0;

	virtual bool WriteWarnLog(const char* szLog) = 0;

	virtual bool WriteInfoLog(const char* szLog) = 0;
};


#endif
