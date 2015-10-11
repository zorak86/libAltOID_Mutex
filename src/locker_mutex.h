#ifndef LOCKER_MUTEX_H
#define LOCKER_MUTEX_H

#include "mutex_instance.h"

/**
 * Locker class for mutex
 * it will release the mutex when the object is deleted (e.g. at the end of a function)
 */
class Locker_Mutex
{
public:
	/**
	 * Locker constructor
	 * @param _mt Mutex instance.
	 * @param _dontlock Don't lock/unlock the mutex at all on constructor/destructor. Useful to automate recursive functions where subsequent locks on the same function could hang the recursion...
	 */
    Locker_Mutex(Mutex_Instance * _mt,bool _dontlock=false);
    /**
     * Locker destructor
	 * After the function ends (after return), C will destroy this object and call this destructor releasing the mutex.
     */
    ~Locker_Mutex();

private:    
    /**
     * Don't lock variable.
     */
    bool dontlock;
    /**
     * Mutex instance to be used.
     */
    Mutex_Instance * mt;
};

#endif // LOCKER_MUTEX_H
