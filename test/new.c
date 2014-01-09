
/**
 * `test/new.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <sphia/sphia.h>
#include <sphia/new.h>
#include <sphia/free.h>
#include <sphia/test.h>

TEST(new_db_create);
TEST(new_db_existing);

TEST(new) {
  HEADER(sphia_new);

  RUN(new_db_create);
  RUN(new_db_existing);

  FOOTER();
}
// create a new db
TEST(new_db_create) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);
  sphia_free(sphia);
  return 0;
}

// open an existing db
TEST(new_db_existing) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);
  sphia_free(sphia);
  return 0;
}
