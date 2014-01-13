
/**
 * `error.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <string.h>
#include <sophia/sophia.h>
#include <sphia/common.h>
#include <sphia/error.h>

char *
sphia_error (sphia_t *self) {
  return sp_error(self->db);
}
