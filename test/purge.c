
/**
 * `test/purge.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <sphia/sphia.h>
#include <sphia/new.h>
#include <sphia/free.h>
#include <sphia/purge.h>
#include <sphia/test.h>

TEST(purge_bad_instance);
TEST(purge_simple);

static char *
temp_file(const char *filename) {
  char *tmp = malloc(256);
  assert(tmp);
  sprintf(tmp, "%s/%s", SPHIA_TEST_DB, filename);
  return tmp;
}

static void
create_file(const char *name) {
  char *path = temp_file(name);
  assert(path);

  FILE *fp = fopen(path, "w");
  assert(fp);
  fclose(fp);

  free(path);
}

static int
file_exists(const char *name) {
  struct stat stats;

  char *path = temp_file(name);
  assert(path);

  int rc = stat(path, &stats);
  free(path);
  return -1 == rc
    ? 0
    : 1;
}

TEST(purge) {
  HEADER(sphia_purge);
  RUN(purge_bad_instance);
  RUN(purge_simple);
  FOOTER();
}

TEST(purge_bad_instance) {
  assert(-1 == sphia_purge(NULL));
  return 0;
}

TEST(purge_simple) {
  const char *files_to_remove[] = {
      "incomplete.foo"
    , "a.incomplete"
    , "1.incomplete"
    , "12345000.incomplete"
    , "foo.bar"
    , NULL
  };

  const char *files_to_keep[] = {
      ".foo"
    , ".bar"
    , "1.log"
    , "thing.log"
    , NULL
  };

  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);

  // create a bunch of mock files

  for (int i = 0; files_to_remove[i]; i++) {
    create_file(files_to_remove[i]);
  }

  for (int i = 0; files_to_keep[i]; i++) {
    create_file(files_to_keep[i]);
  }

  assert(0 == sphia_purge(sphia));
  sphia_free(sphia);

  // verify we've removed the correct
  // files and kept the others

  for (int i = 0; files_to_remove[i]; i++) {
    assert(0 == file_exists(files_to_remove[i]));
  }

  for (int i = 0; files_to_keep[i]; i++) {
    assert(1 == file_exists(files_to_keep[i]));
  }

  return 0;
}

