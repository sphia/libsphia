
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

TEST(simple_set);

TEST(set) {
  HEADER(sphia_set);
  RUN(simple_set);
  FOOTER();
}

TEST(simple_set) {
  sphia_t *sphia = sphia_new("./test-db");
  assert(sphia);

  char key[] = "key";
  char value[] = "value";
  int rc = 0;

  rc = sphia_set(sphia, key, value);

  assert(0 == rc);

  sphia_free(sphia);
  return 0;
}
