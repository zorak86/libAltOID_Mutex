#include "mutex_instance.h"
#include <time.h>

void milliSecsInFuture(timespec *ts, unsigned int millisecs)
{
    clock_gettime(CLOCK_REALTIME, ts);
    if (millisecs>1000)
    {
        ts->tv_sec += millisecs/1000;
        millisecs = millisecs%1000;
    }
    ts->tv_nsec += millisecs * 1000000;
}

Mutex_Instance::Mutex_Instance()
{
    pthread_mutexattr_init(&l_mattr);
    pthread_mutexattr_setpshared(&l_mattr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&l_mp, &l_mattr);
}

void Mutex_Instance::Lock()
{
    pthread_mutex_lock(&l_mp);
}

void Mutex_Instance::UnLock()
{
    pthread_mutex_unlock(&l_mp);
}

int Mutex_Instance::TryLock()
{
    return pthread_mutex_trylock(&l_mp);
}

int Mutex_Instance::TryTimedLockFromNow(unsigned int millisecondsFromNow)
{
    timespec gc_time;
    milliSecsInFuture(&gc_time, millisecondsFromNow);
    return pthread_mutex_timedlock(&l_mp, &gc_time);
}

Mutex_Instance::~Mutex_Instance()
{
    pthread_mutex_destroy(&l_mp);
}
