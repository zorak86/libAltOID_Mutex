#ifndef MUTEX_RW_INSTANCE_H
#define MUTEX_RW_INSTANCE_H

#include <pthread.h>

/**
 * Pure R/W Mutex instance Wrapper.
 * Hold's the R/W mutex object.
 * Useful for multiple readers or one writer at the same time
 */
class Mutex_RW_Instance
{

public:
	/*
	 * Mutex instance constructor.
	 */
    Mutex_RW_Instance();
	/*
	 * Mutex instance destructor.
	 */
    ~Mutex_RW_Instance();

    /**
     * Write Lock function
     * used to write lock the mutex.
     */
    void WRLock();
    /**
     * Read Lock function
     * used to read lock the mutex.
     */
    void RDLock();
    /**
     * UnLock function
     * used to unlock the mutex.
     */
    void UnLock();

    /**
     * Try to Write Lock function
     * used to try write lock the mutex.
     * @return Return zero if successfully locked
     */
    int TryWRLock();
    /**
     * Try to Read Lock function
     * used to try read lock the mutex.
     * @return Return zero if successfully locked
     */
    int TryRDLock();

private:
    /**
     * mutex variable
     */
    pthread_rwlock_t rwlock;
};

#endif // MUTEX_RW_INSTANCE_H
