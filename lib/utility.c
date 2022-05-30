/* utility.c

   Copyright (C) 2022 Ivan Guerreschi.

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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "utility.h"

const char
*file_name (const char *file_password)
{
  char *file;

  if ((file = getenv ("HOME")) == NULL)
    file = getpwuid (getuid ())->pw_dir;

  strcat (file, file_password);

  return file;
}

int
remove_file (const char *file)
{
  if (remove (file) == 0)
    return 0;
  else
    return -1;
}
