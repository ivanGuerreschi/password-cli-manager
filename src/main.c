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
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  int opt;

  while (1)
    {
      static struct option long_options[] =
	{
	  { "all",     no_argument, 0, 'a' },
	  { "create",  required_argument, 0, 'c' },
	  { "delete",  required_argument, 0, 'd' },
	  { "help",    no_argument, 0, 'h' },
	  { "search",  required_argument, 0, 's' },
	  { "version", no_argument, 0, 'v' },
	  { 0, 0 ,0 ,0 }
	};

      int option_index = 0;

      opt = getopt_long (argc, argv, "acdhsv", long_options, &option_index);

      if (opt == -1)
        break;

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
	  exit (EXIT_SUCCESS);
          break;
        case '?':
          fprintf (stderr, "Unknown option character '%c'.\n", optopt);
	  printf ("%s\n", help ());
          exit (EXIT_SUCCESS);
        default:
          exit (EXIT_FAILURE);
        }
    }

  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  return EXIT_SUCCESS;
}
