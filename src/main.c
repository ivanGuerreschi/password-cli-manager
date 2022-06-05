/* main.c

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

#include "include/menu.h"
#include "include/menu_wrapper.h"
#include "info.h"
#include "password.h"
#include "utility.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
  printf ("Password manager version: %s\n\n", print_version ());
  printf ("%s\n\n", print_license ());

  const char *file = file_name (NAMEFILE);
  int menu = 0;

  while (true)
    {
      menu = print_menu ();

      switch (menu)
        {
        case 1:
          exit (1);

        case 2:
          print_all_credential (file);
          break;

        case 3:
          input_create_credential (file);
          break;
        }
    }

  return EXIT_SUCCESS;
}
