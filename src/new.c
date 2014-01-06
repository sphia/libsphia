
#include <stdlib.h>
#include "sphia.h"

/**
 * Create a new database instance from
 * the given `path`, returns `NULL` on error.
 */

sphia_t *
sphia_new(const char *path) {
  int rc = 0;

  sphia_t *sphia = malloc(sizeof(sphia_t));
  if (NULL == sphia) return NULL;

  sphia->path = path;
  sphia->env = NULL;
  sphia->db = NULL;

  sphia->env = sp_env();
  if (NULL == sphia->env) goto fail;

  rc = sp_ctl(sphia->env, SPDIR, SPO_CREAT|SPO_RDWR, path);
  if (-1 == rc) goto fail;

  rc = sp_ctl(sphia->env, SPGC, 1);
  if (-1 == rc) goto fail;

  sphia->db = sp_open(sphia->env);
  if (NULL == sphia->db) goto fail;

  return sphia;

fail:
  sphia_free(sphia);
  return NULL;
}
