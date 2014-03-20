
/**
 * `test/get.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <string.h>
#include <sphia/sphia.h>
#include <sphia/new.h>
#include <sphia/free.h>
#include <sphia/get.h>
#include <sphia/set.h>
#include <sphia/test.h>

TEST(get_simple);

TEST(get) {
  HEADER(sphia_get);
  RUN(get_simple);
  FOOTER();
}

TEST(get_simple) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);

  char key[] = "key";
  char value[] = "value";
  char *actual = NULL;

  assert(0 == sphia_set(sphia, key, value));
  actual = sphia_get(sphia, key);
  assert(actual);
  assert(0 == strncmp(actual, value, strlen(actual)));
  free(actual);
  sphia_free(sphia);
  return 0;
}
