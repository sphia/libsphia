
/**
 * `get.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_GET_H
#define SPHIA_GET_H 1
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "sphia.h"

/**
 * Get the value of `key` in the given `sphia`
 * instance.  The returned value will always
 * be NUL terminated.
 *
 * Returns NULL on error.
 */

SPHIA_EXTERN char *
sphia_get (sphia_t *, const char *);

#ifdef __cplusplus
}
#endif
#endif
