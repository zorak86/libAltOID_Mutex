dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(libAltOID_Mutex, 1.0)
AC_PROG_CC

AC_CANONICAL_SYSTEM

AC_CONFIG_MACRO_DIR([m4])

dnl Initialize automake
AM_INIT_AUTOMAKE

AC_PROG_CXX

# C++11
AC_LANG_CPLUSPLUS
# check C++11 compliance and flags
#AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])

# libraries:
AC_SEARCH_LIBS([pthread_create], [pthread])

#debug:

AC_ARG_ENABLE(debug,
AS_HELP_STRING([--enable-debug],
               [enable debugging, default: no]),
[case "${enableval}" in
             yes) debug=true ;;
             no)  debug=false ;;
             *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
esac],
[debug=false])

AM_CONDITIONAL(DEBUG, test x"$debug" = x"true")


dnl this allows us specify individual liking flags for each target
AM_PROG_CC_C_O 

dnl Initialize Libtool
LT_INIT

AC_CONFIG_FILES(Makefile
                libAltOIDMutex/Makefile
                include/Makefile)
AC_OUTPUT