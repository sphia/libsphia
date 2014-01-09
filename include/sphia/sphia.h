
/**
 * `sphia.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_CORE_H
#define SPHIA_CORE_H 1
#ifdef __cplusplus
extern "C" {
#endif

#include <sophia/sp.h>

/**
 * sphia object that manages core sophia environment
 * and database
 */

typedef struct sphia_s {

  /**
   * Represents the absolute path to the sophia database
   */

  const char *path;

  /**
   * Pointer to the sophia database returned from
   * `sp_open(void *)`
   */

  void *db;

  /**
   * Pointer to the sophia environment returned from
   * `sp_env(void)`
   */

  void *env;

  /**
   * sophia error object for last known error
   */

  spe *error;

} sphia_t;

#ifdef __cplusplus
}
#endif
#endif
