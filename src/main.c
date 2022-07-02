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
#include "search.h"
#include "utility.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
  printf ("Password manager version: %s\n", version ());
  printf ("Bug report: %s\n\n", bugreport ());
  printf ("%s\n\n", license ());

  int menu = 0;
  bool loop = true;

  do
    {
      menu = print_menu ();

      if (menu == 1)
        {
          exit (1);
          loop = false;
        }
      else if (menu == 2)
        {
          print_all_credential ();
          loop = true;
        }
      else if (menu == 3)
        {
          input_create_credential ();
          loop = true;
        }
      else if (menu == 4)
        {
          search_credential ();
          loop = true;
        }
      else if (menu == 5)
        {
          delete_credential ();
          loop = true;
        }
      else
        puts ("Input error (1, 2, 3, 4, 5 are valid option");
    }
  while (loop);

  return EXIT_SUCCESS;
}
