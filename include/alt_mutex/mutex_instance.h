#ifndef MUTEX_INSTANCE_H
#define MUTEX_INSTANCE_H

#include <pthread.h>

/**
 * Pure mutex instance Wrapper.
 * Hold's the mutex object.
 */
class Mutex_Instance
{
public:
	/*
	 * Mutex instance constructor.
	 */
    Mutex_Instance();
	/*
	 * Mutex instance destructor.
	 */
    ~Mutex_Instance();

    /**
     * Lock function
     * used to lock the mutex.
     */
    void Lock();
    /**
     * UnLock function
     * used to unlock the mutex.
     */
    void UnLock();
    /**
     * TryLock function
     * used to try lock the mutex.
     * @return Return zero if successfully locked
     */
    int TryLock();
    /**
     * TryTimedLockFromNow function
     * used to try lock the mutex for some time.
     * @param millisecondsFromNow milliseconds to keep trying before desist and return.
     * @return Return zero if successfully locked
     */
    int TryTimedLockFromNow(unsigned int millisecondsFromNow);

private:
    /**
     * mutex attributes variable
     */
    pthread_mutexattr_t l_mattr;
    /**
     * mutex variable
     */
    pthread_mutex_t l_mp;

};

#endif // MUTEX_INSTANCE_H
