/* file_password_test.c

   Copyright (C) 2022-2023 Ivan Guerreschi.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "include/utility_test.h"
#include "utility.h"
#include <string.h>

int
main (void)
{
  const char *file = file_name (NAMEFILETEST);

  if (strcmp (file, file_name ("/.passwordtest")) == 0)
    return 0;
  else
    return 1;
}
