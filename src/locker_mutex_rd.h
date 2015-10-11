#ifndef LOCKER_MUTEX_RD_H
#define LOCKER_MUTEX_RD_H

#include "mutex_rw_instance.h"

/**
 * Read locker for RD/WR mutex type
 */
class Locker_Mutex_RD
{
public:
	/**
	 * Read Locker constructor.
	 * If instanced at the beginning of the function, it will read-lock the mutex instance.
	 * @param _mt mutex instance.
	 */
	Locker_Mutex_RD(Mutex_RW_Instance *_mt);
	/**
	 * Read Locker destructor.
	 * After the function ends (after return), C will destroy this object and call this destructor releasing the mutex.
	 */
    ~Locker_Mutex_RD();
private:
    /**
     * Mutex instance to be used.
     */
    Mutex_RW_Instance * mt;
};

#endif // LOCKER_MUTEX_RD_H
