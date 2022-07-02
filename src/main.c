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
#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  int opt;

  while ((opt = getopt (argc, argv, "acdhsv")) != -1)
    {
      switch (opt)
        {
        case 'a':
          print_all_credential ();
          break;
        case 'c':
          create_credential ();
          break;
        case 'd':
          delete_credential ();
          break;
        case 'h':
          printf ("%s\n%s\n%s\n", help (), license (), bugreport ());
          break;
        case 's':
          search_credential ();
          break;
        case 'v':
          printf ("%s\n", package ());
          break;
        case '?':
          fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
          return EXIT_SUCCESS;
        default:
          return EXIT_FAILURE;
        }
    }

  return EXIT_SUCCESS;
}
