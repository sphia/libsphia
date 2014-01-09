
/**
 * `new.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <sophia/sp.h>
#include <sophia/sophia.h>
#include <sphia/common.h>
#include <sphia/free.h>
#include <sphia/new.h>

/**
 * Create a new database instance from
 * the given `path`, returns `NULL` on error.
 */

sphia_t *
sphia_new(const char *path) {
  int rc = 0;
  spenv *env = NULL;
  spe *e = NULL;
  sp *db = NULL;

  sphia_t *sphia = (sphia_t *) malloc(sizeof(sphia_t));
  if (NULL == sphia) return NULL;

  sphia->path = path;
  sphia->env = NULL;
  sphia->db = NULL;

  env = (spenv *) sp_env();
  if (NULL == env) goto fail;
  sphia->env = (void *) env;

  rc = sp_ctl(sphia->env, SPDIR, SPO_CREAT|SPO_RDWR, path);
  if (-1 == rc) goto fail;

  rc = sp_ctl(sphia->env, SPGC, 1);
  if (-1 == rc) goto fail;

  db = (sp *) sp_open(sphia->env);
  if (NULL == db) goto fail;
  sphia->db = (void *) db;

  sphia->error = &env->e;
  if (NULL == sphia->error) goto fail;

  return sphia;

fail:
  sphia_free(sphia);
  return NULL;
}
