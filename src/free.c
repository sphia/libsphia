
/**
 * `free.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <sophia.h>
#include <sphia/sphia.h>
#include <sphia/free.h>

/**
 * Free the sphia structure.
 */

void
sphia_free (sphia_t *sphia) {
  sp_destroy(sphia->db);
  sp_destroy(sphia->env);
  free(sphia);
}
