/* menu_wrapper.c

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

#include "include/menu_wrapper.h"
#include "password.h"
#include "utility.h"
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 100

void
print_all_credential (const char *filename)
{
  FILE *file_password, *file_row;
  open_file (&file_password, filename);
  open_file (&file_row, filename);

  size_t row = count_row (file_row);
  credential_t *credential = all (file_password, row);

  puts ("ID Website Username Email Password");

  for (size_t i = 0; i < row; i++)
    {
      printf ("%ld %s %s %s %s\n", i + 1, credential[i].website, credential[i].username,
              credential[i].email, credential[i].password);
    }

  for (size_t i = 0; i < row; i++)
    {
      free (credential[i].website);
      free (credential[i].username);
      free (credential[i].email);
      free (credential[i].password);
    }

  free (credential);
  credential = NULL;
  close_file (&file_row);
  close_file (&file_password);
}

void
input_create_credential (const char *filename)
{
  credential_t credential = { 0, 0, 0, 0 };
  char buffer[BUFFERSIZE] = { 0 };

  puts ("Website");
  char *website = malloc (100 * sizeof (char));
  if (website)
    {
      if (fgets (buffer, sizeof (buffer), stdin))
        {
          buffer[strcspn (buffer, "\r\n")] = 0;
          strncpy (website, buffer, BUFFERSIZE);
          memset (buffer, 0, BUFFERSIZE);
          credential.website = (char *)malloc (100 * sizeof (char));
          if (credential.website)
            strncpy (credential.website, website, BUFFERSIZE);
          else
            {
              fprintf (stderr, "Error allocation failed");
              exit (EXIT_FAILURE);
            }
        }
      else
        {
          int error_number = errno;
          fprintf (stderr, "Error standard input %s\n",
                   strerror (error_number));
          exit (EXIT_FAILURE);
        }
    }
  else
    {
      fprintf (stderr, "Error allocation failed");
      exit (EXIT_FAILURE);
    }

  free (website);
  website = NULL;

  puts ("Username");
  char *username = malloc (100 * sizeof (char));
  if (username)
    {
      if (fgets (buffer, sizeof (buffer), stdin))
        {
          buffer[strcspn (buffer, "\r\n")] = 0;
          strncpy (username, buffer, BUFFERSIZE);
          memset (buffer, 0, BUFFERSIZE);
          credential.username = (char *)malloc (100 * sizeof (char));
          if (credential.username)
            strncpy (credential.username, username, BUFFERSIZE);
          else
            {
              fprintf (stderr, "Error allocation failed");
              exit (EXIT_FAILURE);
            }
        }
      else
        {
          int error_number = errno;
          fprintf (stderr, "Error standard input %s\n",
                   strerror (error_number));
          exit (EXIT_FAILURE);
        }
    }
  else
    {
      fprintf (stderr, "Error allocation failed");
      exit (EXIT_FAILURE);
    }

  free (username);
  username = NULL;

  puts ("Email");
  char *email = malloc (100 * sizeof (char));
  if (email)
    {
      if (fgets (buffer, sizeof (buffer), stdin))
        {
          buffer[strcspn (buffer, "\r\n")] = 0;
          strncpy (email, buffer, BUFFERSIZE);
          memset (buffer, 0, BUFFERSIZE);
          credential.email = malloc (100 * sizeof (char));
          if (credential.email)
            strncpy (credential.email, email, BUFFERSIZE);
          else
            {
              fprintf (stderr, "Error allocation failed");
              exit (EXIT_FAILURE);
            }
        }
      else
        {
          int error_number = errno;
          fprintf (stderr, "Error standard input %s\n",
                   strerror (error_number));
          exit (EXIT_FAILURE);
        }
    }
  else
    {
      fprintf (stderr, "Error allocation failed");
      exit (EXIT_FAILURE);
    }

  free (email);
  email = NULL;

  puts ("Password");
  char *password = malloc (100 * sizeof (char));
  if (password)
    {
      if (fgets (buffer, sizeof (buffer), stdin))
        {
          buffer[strcspn (buffer, "\r\n")] = 0;
          strncpy (password, buffer, BUFFERSIZE);
          credential.password = malloc (100 * sizeof (char));
          if (credential.password)
            strncpy (credential.password, password, BUFFERSIZE);
          else
            {
              fprintf (stderr, "Error allocation failed");
              exit (EXIT_FAILURE);
            }
        }
      else
        {
          int error_number = errno;
          fprintf (stderr, "Error standard input %s", strerror (error_number));
          exit (EXIT_FAILURE);
        }
    }
  else
    {
      fprintf (stderr, "Error allocation failed");
      exit (EXIT_FAILURE);
    }

  free (password);
  password = NULL;

  FILE *file;
  open_file (&file, filename);
  create (file, credential);
  close_file (&file);
}

void
search_credential (const char *filename)
{
  FILE *file_password, *file_row;
  open_file (&file_password, filename);
  open_file (&file_row, filename);

  size_t row = count_row (file_row);
  credential_t *credential = all (file_password, row);

  char buffer[BUFFERSIZE] = { 0 };

  puts ("Enter the key search");
  char *key = malloc (100 * sizeof (char));
  if (key)
    {
      if (fgets (buffer, sizeof (buffer), stdin))
        {
          buffer[strcspn (buffer, "\r\n")] = 0;
          strncpy (key, buffer, BUFFERSIZE);
        }
      else
        {
          int error_number = errno;
          fprintf (stderr, "Error standard input %s\n",
                   strerror (error_number));
          exit (EXIT_FAILURE);
        }
    }
  else
    {
      fprintf (stderr, "Error allocation failed");
      exit (EXIT_FAILURE);
    }

  int result = search (credential, row, key);

  if (result >= 0)
    printf ("Website: %s Username: %s Email: %s Password: %s\n",
            credential[result].website, credential[result].username,
            credential[result].email, credential[result].password);
  else
    puts ("Not found");

  free (key);
  key = NULL;
  free (credential);
  credential = NULL;
  close_file (&file_row);
  close_file (&file_password);
}

void
delete_credential (const char *filename, const char *tmp_filename)
{
  FILE *file_password, *file_tmp;
  open_file (&file_password, filename);
  open_file (&file_tmp, tmp_filename);

  int line = 0;
  char buffer[2] = { 0 };

  puts ("Enter the number line for delete credential");
  char *line_input = malloc (2 * sizeof (char));
  if (line_input)
    {
      if (fgets (buffer, sizeof (buffer), stdin))
        {
          buffer[strcspn (buffer, "\r\n")] = 0;
          strncpy (line_input, buffer, 2);
        }
      else
        {
          int error_number = errno;
          fprintf (stderr, "Error standard input %s\n",
                   strerror (error_number));
          exit (EXIT_FAILURE);
        }
    }

  else
    {
      fprintf (stderr, "Error allocation failed");
      exit (EXIT_FAILURE);
    }

  if (isdigit (line_input[0]))
    {
      line = atoi (line_input);
      rewind (file_password);
      delete (file_password, file_tmp, line);
      if (remove_file (filename) == 0)
        rename (tmp_filename, filename);
      else
        fprintf (stderr, "Error delete file");
    }
  else
    fprintf (stderr, "Error input is not number");

  close_file (&file_password);
  close_file (&file_tmp);
}
