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

file_password_test = executable(
  'filepasswordtest',
  'file_password_test.c',
  dependencies : passwordlib_dep
)
test('file_password_test', file_password_test)

file_password_xfail_test = executable(
  'filepassword_xfail_test',
  'file_password_xfail_test.c',
  dependencies : passwordlib_dep
)
test('file_password_xfail_test', file_password_xfail_test)

new_password_test = executable(
  'newpasswordtest',
  'new_password_test.c',
  dependencies : passwordlib_dep
)
test('new_password_test', new_password_test)

all_password_test = executable(
  'allpasswordtest',
  'all_password_test.c',
  dependencies : passwordlib_dep
)
test('all_password_test', all_password_test)

search_password_test = executable(
  'searchpasswordtest',
  'search_password_test.c',
  dependencies : passwordlib_dep
)
test('search_password_test', search_password_test)

delete_password_test = executable(
  'deletepasswordtest',
  'delete_password_test.c',
  dependencies : passwordlib_dep
)
test('delete_password_test', delete_password_test)

remove_file_password_test = executable(
  'removefilepasswordtest',
  'remove_file_password_test.c',
  dependencies : passwordlib_dep
)
test('remove_file_password_test', remove_file_password_test)

