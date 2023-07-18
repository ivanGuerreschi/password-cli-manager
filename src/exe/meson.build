# meson.build
#
# Copyright (C) 2022-2023 Ivan Guerreschi
#
# Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
# Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>e
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

build_args = [
	'-Wall', '-Wextra', '-Wdouble-promotion', '-Wformat-security', '-Wformat-signedness',  
	'-Winit-self', '-Wshift-overflow=2', '-Wswitch-default', '-Wstrict-overflow=4', '-Walloca',
	'-Warith-conversion', '-Wshadow', '-Wduplicated-branches', '-Wduplicated-cond',
	'-Wcast-qual', '-Wconversion', '-Wdate-time', '-Wstrict-prototypes', '-Wmissing-prototypes',
	'-Winvalid-pch', 
]

project_source_files = [
	'main.c',
  'parse_input.c',
  'parse_wrapper.c',
]

executable(
	'passcliman', 
	project_source_files,
	install : true,
  dependencies : passwordlib_dep,  
	c_args : build_args
)
