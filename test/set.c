
/**
 * `test/set.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <sphia/sphia.h>
#include <sphia/new.h>
#include <sphia/free.h>
#include <sphia/get.h>
#include <sphia/set.h>
#include <sphia/test.h>

TEST(set_simple);

TEST(set) {
  HEADER(sphia_set);
  RUN(set_simple);
  FOOTER();
}

TEST(set_simple) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);

  char key[] = "key";
  char value[] = "value";
  int rc = 0;

  rc = sphia_set(sphia, key, value);

  assert(0 == rc);

  sphia_free(sphia);
  return 0;
}

TEST(set_similar) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  return 0;
}
