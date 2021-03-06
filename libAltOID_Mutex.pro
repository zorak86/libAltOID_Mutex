#--++-----------------------------------------------
#
# Project created by QtCreator 2015-10-08T19:04:13
#
#-------------------------------------------------

QT       -= gui core
CONFIG += c++11

SOURCES += \
    src/locker_mutex_rd.cpp \
    src/locker_mutex_wr.cpp \
    src/locker_mutex.cpp \
    src/mutex_instance.cpp \
    src/mutex_rw_instance.cpp

HEADERS += \
    src/base_mutex_rw.h \
    src/execaroundptr_proxy.h \
    src/locker_mutex_rd.h \
    src/locker_mutex_wr.h \
    src/locker_mutex.h \
    src/locker_rwmutex_allinc.h \
    src/mutex_instance.h \
    src/mutex_rw_instance.h

isEmpty(PREFIX) {
    PREFIX = /usr/local
}

# C++ standard.
QMAKE_CXX += -Wno-write-strings -Wno-unused-parameter -Wno-unused-function -O3 -std=c++11 -Wunused -Wno-unused-result
# LIB DEFS:
TARGET = alt_mutex
TEMPLATE = lib
VERSION      = 3.0.1
# INSTALLATION:
target.path = $$PREFIX/lib
header_files.files = $$HEADERS
header_files.path = $$PREFIX/include/$$TARGET
INSTALLS += target
INSTALLS += header_files

DISTFILES += \
    LICENSE \
    AUTHORS \
    ChangeLog \
    README.md \
    INSTALL \
    autogen.sh \
    configure.ac \
    src/Makefile.am \
    Makefile.am \
    README \
    autogen.sh \
    m4/ax_pthread.m4

build_pass:CONFIG(debug, debug|release) {
    unix: TARGET = $$join(TARGET,,,_debug)
    else: TARGET = $$join(TARGET,,,d)
}

# PKGCONFIG
CONFIG += create_pc create_prl no_install_prl
QMAKE_PKGCONFIG_LIBDIR = $$PREFIX/lib/
QMAKE_PKGCONFIG_INCDIR = $$PREFIX/include/alt_mutex
QMAKE_PKGCONFIG_CFLAGS = -I$$PREFIX/include/
QMAKE_PKGCONFIG_DESTDIR = pkgconfig

