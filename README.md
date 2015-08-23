# libAltOID_Mutex

Alternative OpenSource Mutex Library - by Zorak x86   
License: LGPL v3  
Version: 1.0a  
Requires: libpthread

## Functionality

This library provides C++ abstraction on: 

- Mutex and R/W Mutex
- Locker classes
- Proxy around pointer

## Sample usage for simple R/W mutex class:

```C++

#include "alt_mutex/base_mutex_rw.h"

class SomeClass : public Base_Mutex_RW
{
public:
	SomeClass() { i=0; }

	int ReadI() 
	{ 
		Locker_Mutex_RD rdlock(&rwl);		
		return i;
	}
	void WriteI(int _i)
	{
		Locker_Mutex_WR rdlock(&rwl);
		i=_i; 
	}
	
private:
	int i;
}

```

## Sample usage for simple execute around proxy interface.

The protection should be implemented like:

```C++
#include "alt_mutex/locker_rwmutex_allinc.h"
#include "alt_mutex/execaroundptr_proxy.h"
// Your another class..
#include "anotherclass.h"

class SomeClass
{
public:
	SomeClass() { X=NULL; }
	void setAnotherClass(AnotherClass * currentAnotherClass)
	{
		// Prevent overwrite X during X function executions...
		Locker_Mutex_WR xlock(&rwl);
		X = currentAnotherClass;		
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* The mutex proxy for class AnotherClass...
	*/
	class AnotherClass_Proxy : public ExecAroundPTR_Proxy
	{
	public:
		AnotherClass_Proxy(void * v, Mutex_RW_Instance * m) : ExecAroundPTR_Proxy(v,m) {}
		AnotherClass * operator -> () { return (AnotherClass *)item; }
	};

	AnotherClass_Proxy GetAnotherClassByProxy()
	{
		Locker_Mutex_RD xlock(&rwl);
		return Firewall_Instance_Proxy(&X, &rwl);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

private:
	AnotherClass * X;
	Mutex_RW_Instance rwl;
};
```

And the call:

```C++

// Some global...
SomeClass someClass;

// And... In another threads:
someClass.GetAnotherClassByProxy()->MethodOfAnotherClass("Hello World");

```

And the method of another class will be called. But X will not be modified during those calls.
