
#include "tests.h"
#include "sphia.h"

// create a new db
TEST(new_db_create) {
  sphia_t *sphia = sphia_new("./test-db");
  assert(sphia);
  sphia_free(sphia);
  return 0;
}

// open an existing db
TEST(new_db_existing) {
  sphia_t *sphia = sphia_new("./test-db");
  assert(sphia);
  sphia_free(sphia);
  return 0;
}
