
/**
 * `set.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */


#include <string.h>
#include <sophia.h>
#include <sphia/common.h>
#include <sphia/set.h>

int
sphia_set (sphia_t *self, const char *key, const char *value) {
  size_t ksize = strlen(key) + 1;
  size_t vsize = strlen(value) + 1;
  return sp_set(self->db, key, ksize, value, vsize);
}
