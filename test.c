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

  /**
   * Tests to run
   **/

  RUN(new);
  RUN(free);
  RUN(get);
  RUN(set);
  RUN(rm);
  RUN(clear);
  RUN(count);
  RUN(purge);
  RUN(error);
  RUN(iterator);

  printf("\n-------------------------\n");
  printf("  libsphia test results");
  printf("\n-------------------------");

  FOOTER();
}
