# Makefile.am
#
# Copyright (C) 2022 Ivan Guerreschi
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

AM_CFLAGS = -I $(top_srcdir)/src -I $(top_srcdir)/lib \
	    -Wall -Wextra -Wformat=2 -Wno-unused-parameter -Wshadow \
            -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
            -Wredundant-decls -Wnested-externs -Wmissing-include-dirs \
	    -Wjump-misses-init -Wlogical-op

nobase_include_HEADERS = include/parse_wrapper.h include/parse_input.h
bin_PROGRAMS = passwordclimanager
passwordclimanager_SOURCES = main.c parse_wrapper.c parse_input.c
passwordclimanager_LDADD = $(top_builddir)/lib/libpassword.a $(AM_LDFLAGS)
