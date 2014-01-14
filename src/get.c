
/**
 * `get.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <string.h>
#include <sophia.h>
#include <sphia/common.h>
#include <sphia/get.h>

char *
sphia_get (sphia_t *self, const char *key) {
  size_t size = strlen(key) + 1;
  size_t vsize = 0;
  void *ref = NULL;
  char *value = NULL;
  int rc = 0;

  rc = sp_get(self->db, key, size, &ref, &vsize);

  switch (rc) {
    // unknown error
    case -1:
    // not found
    case 0:
      break;

    // found
    case 1:
      value = (char *) ref;
      if ('\0' != value[vsize]) value[vsize] = '\0';
      return value;
  }

  return NULL;
}
