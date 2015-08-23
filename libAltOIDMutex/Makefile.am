#######################################
# The list of libraries we are building seperated by spaces.
# The 'lib_' indicates that these build products will be installed
# in the $(libdir) directory. For example /usr/lib
lib_LTLIBRARIES = libAltOIDMutex.la

#######################################
# Build information for each library

# Sources for libAltOIDMutex
libAltOIDMutex_la_SOURCES = locker_mutex_wr.cpp mutex_rw_instance.cpp locker_mutex_rd.cpp mutex_instance.cpp locker_mutex.cpp

# Linker options libTestProgram
libAltOIDMutex_la_LDFLAGS = 

# Compiler options. Here we are adding the include directory
# to be searched for headers included in the source code.
libAltOIDMutex_la_CPPFLAGS = -I$(top_srcdir)/include

if DEBUG
AM_CFLAGS = -g3 -O0
AM_CXXFLAGS = -g3 -O0
else
AM_CFLAGS = -O2
AM_CXXFLAGS = -O2
endif
