
/**
 * `set.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_SET_H
#define SPHIA_SET_H 1
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "sphia.h"

/**
 * Set `key=value` in the given `sphia` instance.
 *
 * Returns 0 on success, -1 on failure.
 */

SPHIA_EXTERN int
sphia_set (sphia_t *, const char *, const char *);

#ifdef __cplusplus
}
#endif
#endif
