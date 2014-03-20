
/**
 * `test/clear.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <sophia.h>
#include <sphia/sphia.h>
#include <sphia/new.h>
#include <sphia/free.h>
#include <sphia/set.h>
#include <sphia/get.h>
#include <sphia/count.h>
#include <sphia/clear.h>
#include <sphia/test.h>

TEST(simple_clear);
TEST(clear_5000_keys);

TEST(clear) {
  HEADER(sphia_clear);
  RUN(simple_clear);
  RUN(clear_5000_keys);
  FOOTER();
}

TEST(simple_clear) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);

  for (int i = 0; i < 20; i++) {
    char *key = malloc(8);
    sprintf(key, "key%02d", i);
    assert(0 == sphia_set(sphia, key, "value"));
    free(key);
  }

  assert(0 == sphia_clear(sphia));

  // cheap check to count keys
  void *c = sp_cursor(sphia->db, SPGT, NULL, 0);
  assert(c);
  assert(0 == sp_fetch(c));
  sp_destroy(c);

  sphia_free(sphia);
  return 0;
}

TEST(clear_5000_keys) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);

  for (int i = 0; i < 5000; i++) {
    char *key = malloc(8);
    sprintf(key, "key%04d", i);
    assert(0 == sphia_set(sphia, key, "value"));
    free(key);
  }

  assert(5000 == sphia_count(sphia));
  assert(0 == sphia_clear(sphia));
  assert(0 == sphia_count(sphia));

  sphia_free(sphia);
  return 0;
}
