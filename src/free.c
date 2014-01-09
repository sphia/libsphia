
/**
 * `free.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <sophia/sophia.h>
#include <sphia/common.h>
#include <sphia/free.h>

/**
 * Free the sphia structure.
 */

void
sphia_free(sphia_t *sphia) {
  if (sphia->env) sp_destroy(sphia->env);
  if (sphia->db) sp_destroy(sphia->db);
  free(sphia);
}
