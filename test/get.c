
#include "tests.h"
#include "sphia.h"

TEST(simple_get);

TEST(get) {
  HEADER(sphia_get);
  RUN(simple_get);
  FOOTER();
}

TEST(simple_get) {
  sphia_t *sphia = sphia_new("./test-db");
  assert(sphia);

  char key[] = "key";
  char value[] = "value";
  char *actual = NULL;

  actual = sphia_get(sphia, key);
  assert(actual);
  assert(0 == strncmp(actual, value, strlen(actual)));
  sphia_free(sphia);
  return 0;
}
