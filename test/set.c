
/**
 * `test/set.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <string.h>
#include <sphia/sphia.h>
#include <sphia/new.h>
#include <sphia/free.h>
#include <sphia/get.h>
#include <sphia/set.h>
#include <sphia/test.h>

TEST(set_simple);
TEST(set_similar);

TEST(set) {
  HEADER(sphia_set);
  RUN(set_simple);
  RUN(set_similar);
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

  assert(sphia);

  char **item = NULL;
  char *pairs[][2] = {
    {"k", "a"},
    {"ke", "b"},
    {"key", "c"},
    {"key-", "d"},
    {"key-k", "e"},
    {"kk", "f"},
    {"ek", "g"},
    {"yek", "h"},
    {"kkeeyy", "i"},
    {"kkey", "j"},
    {"keey", "k"},
    {"keyy", "l"},
    {"ke0", "m"},
    {"key0", "n"},
    {"key00", "o"},
    {"key000", "p"},
    {"key0000-", "q"},
    {NULL, NULL}
  };

  int i = 0;
  char *key = NULL;
  char *val = NULL;
  char *tmp = NULL;

  while (NULL != (item = pairs[i++])) {
    key = item[0];
    val = item[1];
    if (NULL == key) break;
    assert(0 == sphia_set(sphia, key, val));
  }

  i = 0;
  while (NULL != (item = pairs[i++])) {
    key = item[0];
    val = item[1];
    if (NULL == key) break;
    assert(0 == strncmp(val, (tmp = sphia_get(sphia, key)), strlen(val)));
    free(tmp);
  }

  sphia_free(sphia);
  return 0;
}
