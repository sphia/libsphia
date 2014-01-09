
/**
 * `test/free.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <sphia/sphia.h>
#include <sphia/new.h>
#include <sphia/free.h>
#include <sphia/test.h>

TEST(free_empty);
TEST(free_new_db);

TEST(free) {
  HEADER(sphia_free);

  RUN(free_empty);
  RUN(free_new_db);

  FOOTER();
}

// free empty struct
TEST(free_empty) {
  sphia_t *sphia = malloc(sizeof(sphia_t));
  sphia_free(sphia);
  return 0;
}

// free actual db pointers
TEST(free_new_db) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);
  sphia_free(sphia);
  return 0;
}
