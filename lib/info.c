/* info.c

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

#include "info.h"
#include <string.h>

const char *
version (void)
{
  return VERSION;
}

const char *
package (void)
{
  return PACKAGE_STRING;
}

const char *
bugreport (void)
{
  return PACKAGE_BUGREPORT;
}

const char *
license (void)
{
  return "This program is free software: you can redistribute it and/or "
         "modify\n"
         "it under the terms of the GNU General Public License as published "
         "by\n"
         "the Free Software Foundation, either version 3 of the License, or\n"
         "(at your option) any later version.\n\n"

         "This program is distributed in the hope that it will be useful,\n"
         "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
         "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
         "GNU General Public License for more details.\n\n"

         "You should have received a copy of the GNU General Public License\n"
         "along with this program.  If not, see "
         "<https://www.gnu.org/licenses/>.\n";
}

const char *
help (void)
{
  const char *options = "password-cli-manager options\n"
                        "Options:\n"
                        "  -a All credential\n"
                        "  -c Create credential\n"
                        "  -d Delete credential\n"
                        "  -h Help\n"
                        "  -s Search credential\n"
                        "  -v Program version\n";

  return options;
}
