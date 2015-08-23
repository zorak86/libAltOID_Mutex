#include "../include/alt_mutex/locker_mutex_rd.h"

Locker_Mutex_RD::Locker_Mutex_RD(Mutex_RW_Instance *_mt)
{
    mt = _mt;
    mt->RDLock();
}

Locker_Mutex_RD::~Locker_Mutex_RD()
{
    mt->UnLock();
}
