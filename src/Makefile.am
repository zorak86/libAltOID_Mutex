lib_LTLIBRARIES = libalt_mutex.la

pkginclude_HEADERS = base_mutex_rw.h execaroundptr_proxy.h locker_mutex.h locker_mutex_rd.h locker_mutex_wr.h locker_rwmutex_allinc.h mutex_instance.h mutex_rw_instance.h

libalt_mutex_la_SOURCES = base_mutex_rw.h execaroundptr_proxy.h locker_mutex.cpp locker_mutex.h locker_mutex_rd.cpp locker_mutex_rd.h locker_mutex_wr.cpp locker_mutex_wr.h locker_rwmutex_allinc.h mutex_instance.cpp mutex_instance.h mutex_rw_instance.cpp mutex_rw_instance.h 
libalt_mutex_la_CPPFLAGS = $(PTHREAD_CFLAGS)
libalt_mutex_la_LDFLAGS = $(PTHREAD_LIBS) -no-undefined -export-dynamic -version-info @version_info@
