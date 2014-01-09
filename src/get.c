
/**
 * `get.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <string.h>
#include <sophia/sp.h>
#include <sophia/sophia.h>
#include <sphia/common.h>
#include <sphia/get.h>

char *
sphia_get (sphia_t *self, const char *key) {
  size_t size = strlen(key) + 1;
  size_t vsize = 0;
  void *value = NULL;
  int rc = 0;

  spe *e = self->env;
  rc = sp_get(self->db, key, size, &value, &vsize);

  switch (rc) {
    // unknown error
    case -1: break;

    // not found
    case 0: break;

    // found
    case 1:
      return value;
      break;
  }

  return NULL;
}
