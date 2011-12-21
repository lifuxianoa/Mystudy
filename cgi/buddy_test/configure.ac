#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([buddy-daemon], [0.1])
AM_INIT_AUTOMAKE(buddy, 0.1)
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

AC_CANONICAL_HOST

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h string.h sys/ioctl.h sys/socket.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([inet_ntoa socket strchr])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/config/Makefile
                 src/download/Makefile
                 src/file/Makefile
                 src/service/Makefile
                 src/sysinfo/Makefile])
AC_OUTPUT
