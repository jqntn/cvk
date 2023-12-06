#include "cvk.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
  if (puts("hi") == EOF) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}