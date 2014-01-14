
/**
 * `test/rm.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <sphia/sphia.h>
#include <sphia/new.h>
#include <sphia/free.h>
#include <sphia/set.h>
#include <sphia/clear.h>
#include <sphia/count.h>
#include <sphia/test.h>

TEST(count_bad_instance);
TEST(simple_count);

TEST(count) {
  HEADER(sphia_count);
  RUN(count_bad_instance);
  RUN(simple_count);
  FOOTER();
}

TEST(count_bad_instance) {
  assert(-1 == sphia_count(NULL));
  return 0;
}

TEST(simple_count) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);

  // clear, just in case
  assert(0 == sphia_clear(sphia));
  assert(0 == sphia_count(sphia));

  int num = 1234;

  for (int i = 0; i < num; i++) {
    char *key = malloc(16);
    sprintf(key, "key%03d", i);
    assert(0 == sphia_set(sphia, key, "value"));
  }

  assert(num == sphia_count(sphia));
  assert(0 == sphia_clear(sphia));
  assert(0 == sphia_count(sphia));

  sphia_free(sphia);
  return 0;
}
