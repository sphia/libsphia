
/**
 * `sphia.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_H
#define SPHIA_H 1
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  const char *path;
  void *db;
  void *env;
} sphia_t;

#include <sophia/sophia.h>
#include <sophia/sp.h>
#include "sphia/new.h"
#include "sphia/free.h"

#ifdef __cplusplus
}
#endif
#endif
