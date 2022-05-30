dnl Makefile.am
dnl
dnl Copyright (C) 2022 Ivan Guerreschi.
dnl
dnl Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
dnl Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>e
dnl
dnl This program is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation, either version 3 of the License, or
dnl (at your option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program.  If not, see <http://www.gnu.org/licenses/>.

AC_INIT([password-cli-manager], [1.0], [ivanguerreschi86@gmail.com])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/main.c])
AC_PROG_RANLIB

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])
AC_CHECK_HEADER_STDBOOL
AC_CHECK_FUNCS([memset])
AC_CHECK_FUNCS([strcspn])

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC

AC_CONFIG_FILES([Makefile
	lib/Makefile
	src/Makefile
	tests/Makefile])
AC_OUTPUT
