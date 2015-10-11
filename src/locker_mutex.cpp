#include "locker_mutex.h"

Locker_Mutex::Locker_Mutex(Mutex_Instance * _mt, bool _dontlock)
{
    dontlock = _dontlock;
    if (dontlock) return;
    mt = _mt;
    mt->Lock();
}

Locker_Mutex::~Locker_Mutex()
{
    if (dontlock) return;
    mt->UnLock();
}
