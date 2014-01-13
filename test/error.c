
/**
 * `test/error.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <string.h>
#include <sophia/sophia.h>
#include <sphia/sphia.h>
#include <sphia/new.h>
#include <sphia/free.h>
#include <sphia/error.h>
#include <sphia/test.h>

TEST(simple_error);

TEST(error) {
  HEADER(sphia_error);
  RUN(simple_error);
  FOOTER();
}

TEST(simple_error) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);

  void *c = sp_cursor(sphia->db, SPGT, NULL, 0);
  assert(c);
  int key = 1234;
  sp_delete(sphia->db, &key, sizeof(key));
  sp_destroy(c);

  char *err = sphia_error(sphia);
    // TODO hard-coding this may not be ideal
  assert(0 == strcmp(err, "error: modify with open cursor"));

  sphia_free(sphia);
  return 0;
}
