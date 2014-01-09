
/**
 * `clear.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <string.h>
#include <sophia/sp.h>
#include <sophia/sophia.h>
#include <sphia/common.h>
#include <sphia/rm.h>
#include <sphia/clear.h>

int
sphia_clear (sphia_t *self) {
  if (NULL == self) return -1;

  void *c = sp_cursor(self->db, SPGT, NULL, 0);
  if (NULL == c) return -1;

    // TODO remove magic number
  char *keys[4096];
  int count = 0;

  while (sp_fetch(c)) {
    const char *key = sp_key(c);
    if (key) {
      count++;
      keys[count] = key;
    }
  }

  sp_destroy(c);

  if (0 == count) return 0;

  for (int i = 1; i <= count; i++) {
    const char *key = keys[i];
    if (-1 == sphia_rm(self, key)) return -1;
  }

  return 0;
}
