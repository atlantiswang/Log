#include "lock.h"

Lock::Lock()
{
	InitializeCriticalSection(&m_lock);
}

Lock::~Lock()
{
	DeleteCriticalSection(&m_lock);
}

void Lock::LockWork()
{
	EnterCriticalSection(&m_lock);
}

void Lock::UnLock()
{
	LeaveCriticalSection(&m_lock);
}