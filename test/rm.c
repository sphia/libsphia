
/**
 * `test/rm.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <sphia/sphia.h>
#include <sphia/new.h>
#include <sphia/free.h>
#include <sphia/set.h>
#include <sphia/get.h>
#include <sphia/rm.h>
#include <sphia/test.h>

TEST(simple_rm);
TEST(similar_keys_rm);

TEST(rm) {
  HEADER(sphia_rm);
  RUN(simple_rm);
  RUN(similar_keys_rm);
  FOOTER();
}

TEST(simple_rm) {
  sphia_t *sphia = sphia_new("./test-db");
  assert(sphia);

  assert(0 == sphia_set(sphia, "key", "value"));
  assert(0 == sphia_rm(sphia, "key"));
  assert(NULL == sphia_get(sphia, "key"));

  sphia_free(sphia);
  return 0;
}

TEST(similar_keys_rm) {
  sphia_t *sphia = sphia_new("./test-db");
  assert(sphia);

  char *keys[] = {
      "key"
    , "key0"
    , "key00"
    , "key10"
    , "key01"
    , NULL
  };

  for (int i = 0; keys[i]; i++)
    assert(0 == sphia_set(sphia, keys[i], "hello world!!"));

  for (int i = 0; keys[i]; i++) {
    assert(0 == sphia_rm(sphia, keys[i]));
    assert(NULL == sphia_get(sphia, keys[i]));
  }

  sphia_free(sphia);
  return 0;
}
