#include "locker_mutex_wr.h"

Locker_Mutex_WR::Locker_Mutex_WR(Mutex_RW_Instance *_mt, bool _dontlock)
{
    dontlock=_dontlock;
    if (dontlock) { return; }
    mt = _mt;
    mt->WRLock();
}

Locker_Mutex_WR::~Locker_Mutex_WR()
{
    if (dontlock) { return; }
    mt->UnLock();
}
