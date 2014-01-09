
/**
 * `test.c' - libidna
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sphia/test.h>

int
main (void) {

  // new
  RUN(new);

  // free
  RUN(free);

  // get
  RUN(get);

  // set
  RUN(set);

  // rm
  RUN(rm);

  // clear
  RUN(clear);

  printf("\n-------------------------\n");
  printf("  libsphia test results");
  printf("\n-------------------------");
  FOOTER();
}
