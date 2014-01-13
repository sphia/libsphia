
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
#include <sphia/count.h>
#include <sphia/clear.h>

int
sphia_clear (sphia_t *self) {
  if (NULL == self) return -1;

  // get number of keys in db
  int size = sphia_count(self);
  if (0 == size) return 0;

  int index = 0;
  // buffer for all keys
  char *keys[size];

  void *c = sp_cursor(self->db, SPGT, NULL, 0);
  if (NULL == c) return -1;

  // build array of keys
  while (sp_fetch(c)) {
    char *key = (char *) sp_key(c);
    if (key) {
      keys[index] = key;
      index++;
    }
  }

  sp_destroy(c);

  // not sure how we could end up here, but
  // doesn't hurt to check
  if (size != index) return -1;
  if (0 == index) return 0;

  for (int i = 0; i < size; i++) {
    if (-1 == sphia_rm(self, keys[i])) return -1;
  }

  return 0;
}
