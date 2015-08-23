#include "alt_mutex/mutex_rw_instance.h"

Mutex_RW_Instance::Mutex_RW_Instance()
{
    pthread_rwlock_init(&rwlock,NULL);
}

void Mutex_RW_Instance::WRLock()
{
    pthread_rwlock_wrlock(&rwlock);
}

void Mutex_RW_Instance::RDLock()
{
    pthread_rwlock_rdlock(&rwlock);
}

void Mutex_RW_Instance::UnLock()
{
    pthread_rwlock_unlock(&rwlock);
}

int Mutex_RW_Instance::TryRDLock()
{
    return pthread_rwlock_tryrdlock(&rwlock);
}

int Mutex_RW_Instance::TryWRLock()
{
    return pthread_rwlock_trywrlock(&rwlock);
}

Mutex_RW_Instance::~Mutex_RW_Instance()
{
    pthread_rwlock_destroy(&rwlock);
}
