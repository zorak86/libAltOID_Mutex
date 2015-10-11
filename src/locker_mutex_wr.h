#ifndef LOCKER_MUTEX_WR_H
#define LOCKER_MUTEX_WR_H

#include "mutex_rw_instance.h"

/**
 * Write locker for RD/WR mutex type
 */
class Locker_Mutex_WR
{
public:
	/**
	 * Write Locker constructor.
	 * If instanced at the beginning of the function, it will write-lock the mutex instance.
	 * @param _mt mutex instance.
	 * @param _dontlock don't lock/unlock the mutex at all on constructor/destructor. Useful to automate recursive functions where subsequent locks on the same function could hang the recursion...
	 */
    Locker_Mutex_WR(Mutex_RW_Instance *_mt, bool _dontlock=false);
	/**
	 * Write Locker destructor.
	 * After the function ends (after return), C will destroy this object and call this destructor releasing the mutex.
	 */
    ~Locker_Mutex_WR();
private:
    /**
     * Don't lock variable.
     */
    bool dontlock;
    /**
     * Mutex instance to be used.
     */
    Mutex_RW_Instance * mt;
};


#endif // LOCKER_MUTEX_WR_H
