#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT([sct], [0.0.1], [])
AC_CONFIG_SRCDIR([src/getnrand.c])
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_LANG([C])

AM_INIT_AUTOMAKE([-Wall foreign dist-xz])


# Checks for programs.
AC_PROG_CC

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h inttypes.h stdint.h unistd.h limits.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT64_T
AC_C_INLINE

# Checks for library functions.
AC_CHECK_FUNCS([strtoumax getrandom])
AC_CHECK_DECLS([getrandom],[],[],[#include <sys/random.h>])

AC_OUTPUT
