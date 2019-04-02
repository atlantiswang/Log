#ifndef	_ILOG_H_
#define _ILOG_H_

class Ilog
{
public:
	Ilog(){}
	
	~Ilog(){}
	
	virtual bool WriteErrorLog(const char* szLog) = 0;

	virtual bool WriteWarnLog(const char* szLog) = 0;

	virtual bool WriteInfoLog(const char* szLog) = 0;
};


#endif
