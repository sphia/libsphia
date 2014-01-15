
/**
 * `rm.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <string.h>
#include <sophia.h>
#include <sphia/common.h>
#include <sphia/rm.h>

int
sphia_rm (sphia_t *self, const char *key) {
  if (NULL == self || NULL == key) return -1;
  size_t keysize = strlen(key) + 1;
  return sp_delete(self->db, key, keysize);
}
