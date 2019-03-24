#ifndef _LOCK_H_
#define _LOCK_H_
#include "Ilock.h"
#include <windows.h>

class Lock :public ILock
{
public:
	Lock();

	~Lock();

	virtual void LockWork();

	virtual void UnLock();
private:
	CRITICAL_SECTION m_lock;
};


#endif
