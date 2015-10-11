#ifndef BASE_MUTEX_RW_H
#define BASE_MUTEX_RW_H

#include "locker_rwmutex_allinc.h"
#include "mutex_rw_instance.h"

/**
 * Base class for automating the use of one R/W mutex per object/class
 */
class Base_Mutex_RW
{
public:
	/**
	 * Constructor
	 */
    Base_Mutex_RW() : nilInit(false) {}
    /**
     * Set NIL Init variable.
     * actually does nothing...
     */
    void setNilInit(bool value)
    {
        nilInit = value;
    }

protected:
    /**
     * Assigned RWL mutex.
     */
    Mutex_RW_Instance rwl;
    /**
     * NIL init variable (does nothing)
     */
    bool nilInit;
};

#endif // BASE_MUTEX_RW_H
