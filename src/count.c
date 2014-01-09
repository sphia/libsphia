
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
#include <sphia/count.h>

int
sphia_count (sphia_t *self) {
  if (NULL == self) return -1;

  void *c = sp_cursor(self->db, SPGT, NULL, 0);
  if (NULL == c) return -1;

  int count = 0;

  while (sp_fetch(c)) {
    if (sp_key(c)) count++;
  }

  sp_destroy(c);

  return count;
}
