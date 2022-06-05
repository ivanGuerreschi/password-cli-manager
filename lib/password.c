/* password.c

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

#include "password.h"
#include "utility.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
open_file (FILE **file, const char *filename)
{
  if ((*file = fopen (filename, "a+")) == NULL)
    {
      int error_number = errno;
      fprintf (stderr, "Error open file /home/user/.password %s\n",
               strerror (error_number));
      exit (EXIT_FAILURE);
    }
}

void
close_file (FILE **file)
{
  if (fclose (*file) != 0)
    {
      int error_number = errno;
      fprintf (stderr, "Error close file /home/user/.password %s\n",
               strerror (error_number));
      exit (EXIT_FAILURE);
    }
}

size_t
count_row (FILE *file)
{
  char c;
  int count = 0;

  for (c = getc (file); c != EOF; c = getc (file))
    if (c == '\n')
      count++;

  return count;
}

credential_t *
all_credential (FILE *file, size_t row)
{
  credential_t *credential = calloc (row + 1, sizeof (credential_t));

  if (!credential)
    {
      fprintf (stderr, "Error allocation failed");
      exit (EXIT_FAILURE);
    }

  for (size_t i = 0; i < row; i++)
    {
      credential[i].website = malloc (100 * sizeof (char));
      if (!credential[i].website)
        {
          fprintf (stderr, "Error allocation failed");
          exit (EXIT_FAILURE);
        }

      credential[i].email = malloc (100 * sizeof (char));
      if (!credential[i].email)
        {
          fprintf (stderr, "Error allocation failed");
          exit (EXIT_FAILURE);
        }

      credential[i].username = malloc (100 * sizeof (char));
      if (!credential[i].username)
        {
          fprintf (stderr, "Error allocation failed");
          exit (EXIT_FAILURE);
        }

      credential[i].password = malloc (100 * sizeof (char));
      if (!credential[i].password)
        {
          fprintf (stderr, "Error allocation failed");
          exit (EXIT_FAILURE);
        }
    }

  int n = 0;
  int res = 0;

  while (1)
    {
      res = fscanf (file, "%s", credential[n].website);
      if (res != 1)
        break;

      res = fscanf (file, "%s", credential[n].username);
      if (res != 1)
        break;

      res = fscanf (file, "%s", credential[n].email);
      if (res != 1)
        break;

      res = fscanf (file, "%s", credential[n].password);
      if (res != 1)
        {
          int error_number = errno;
          fprintf (stderr, "Error read file /home/user/.password %s\n",
                   strerror (error_number));
          exit (EXIT_FAILURE);
        }

      n++;
    }

  return credential;
}

void
create_credential (FILE *file, credential_t credential)
{
  char buffer[BUFSIZ];
  char *new_credential = calloc (1, 1);

  if (!new_credential)
    {
      fprintf (stderr, "Error allocation failed");
      exit (EXIT_FAILURE);
    }
  else
    {
      strcpy (buffer, credential.website);
      new_credential = realloc (new_credential,
                                strlen (new_credential) + 2 + strlen (buffer));
      if (!new_credential)
        {
          fprintf (stderr, "Error allocation failed");
          exit (EXIT_FAILURE);
        }
      else
        strcat (new_credential, strcat (buffer, " "));

      strcpy (buffer, credential.username);
      new_credential = realloc (new_credential,
                                strlen (new_credential) + 2 + strlen (buffer));
      if (!new_credential)
        {
          fprintf (stderr, "Error allocation failed");
          exit (EXIT_FAILURE);
        }
      else
        strcat (new_credential, strcat (buffer, " "));

      strcpy (buffer, credential.email);
      new_credential = realloc (new_credential,
                                strlen (new_credential) + 2 + strlen (buffer));
      if (!new_credential)
        {
          fprintf (stderr, "Error allocation failed");
          exit (EXIT_FAILURE);
        }
      else
        strcat (new_credential, strcat (buffer, " "));

      strcpy (buffer, credential.password);
      new_credential = realloc (new_credential,
                                strlen (new_credential) + 2 + strlen (buffer));
      if (!new_credential)
        {
          fprintf (stderr, "Error allocation failed");
          exit (EXIT_FAILURE);
        }
      else
        strcat (new_credential, strcat (buffer, " "));

      printf ("%s\n", new_credential);

      fprintf (file, "%s\n", new_credential);
    }

  free (credential.website);
  free (credential.username);
  free (credential.email);
  free (credential.password);
  free (new_credential);
}
