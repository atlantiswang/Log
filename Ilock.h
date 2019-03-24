#ifndef _ILOCK_H_
#define _ILOCK_H_

class ILock
{
public:
	virtual void LockWork() = 0;
	
	virtual void UnLock() = 0;
};

#pragma once
#endif // 
