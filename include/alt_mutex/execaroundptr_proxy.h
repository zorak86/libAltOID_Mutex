#ifndef ExecAroundPTR_Proxy_H
#define ExecAroundPTR_Proxy_H

#include "mutex_rw_instance.h"

/**
 * Base Class for proxying objects in class to do "execution around proxy"
 * The object can be called by multiple objects simoultaneously, but you can write-lock the
 * same mutex to prevent deleting the object during some internal execution.
 */
class ExecAroundPTR_Proxy
{
public:
	/**
	 * Proxy base constructor for Execution around proxy.
	 * When proxy is generated, we read-lock the assigned mutex.
	 * @param v Object to protect.
	 * @param m Asociated mutex.
	 */
	ExecAroundPTR_Proxy(void * v, Mutex_RW_Instance * m) : item(v), mutex(m)
    {
        m->RDLock();
    }
    //! A destructor.
    /*!
      Execution around proxy,
    */
	/**
	 * Proxy base destructor for Execution around proxy.
	 * when proxy is deleted, we release the assigned mutex.
	 */
    ~ExecAroundPTR_Proxy()
    {
        mutex->UnLock();
    }
protected:
    /**
     * Object to be protected.
     */
    void * item;
    /**
     * mutex instance.
     * */
    Mutex_RW_Instance * mutex;
};

#endif // ExecAroundPTR_Proxy_H
