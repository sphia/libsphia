
/**
 * `test.c' - libidna
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "test/tests.h"

static int TESTS_PASSED = 0;
static int TESTS_FAILED = 0;

int
main (void) {
  HEADER(libsphia);

  // run all tests

  // new
  RUN(new_db_create);
  RUN(new_db_existing);

  // free
  RUN(free_empty);
  RUN(free_new_db);

  FOOTER();
}
