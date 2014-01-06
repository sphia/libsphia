
#include "tests.h"
#include "sphia.h"

// free empty struct
TEST(free_empty) {
  sphia_t *sphia = malloc(sizeof(sphia_t));
  sphia_free(sphia);
  return 0;
}

// free actual db pointers
TEST(free_new_db) {
  sphia_t *sphia = sphia_new("./test-db");
  assert(sphia);
  sphia_free(sphia);
  return 0;
}
