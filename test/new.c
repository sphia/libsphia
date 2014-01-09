
#include "tests.h"
#include "sphia.h"

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
