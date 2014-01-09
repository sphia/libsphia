
/**
 * `test/get.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <sphia/sphia.h>
#include <sphia/new.h>
#include <sphia/free.h>
#include <sphia/get.h>
#include <sphia/set.h>
#include <sphia/test.h>

TEST(simple_get);

TEST(get) {
  HEADER(sphia_get);
  RUN(simple_get);
  FOOTER();
}

TEST(simple_get) {
  sphia_t *sphia = sphia_new("./test-db");
  assert(sphia);

  char key[] = "key";
  char value[] = "value";
  char *actual = NULL;

  assert(0 == sphia_set(sphia, key, value));
  actual = sphia_get(sphia, key);
  assert(actual);
  assert(0 == strncmp(actual, value, strlen(actual)));
  sphia_free(sphia);
  return 0;
}
