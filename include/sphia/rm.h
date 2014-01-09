
/**
 * `rm.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_RM_H
#define SPHIA_RM_H 1
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "sphia.h"

/**
 * Remove `key` from the given `sphia` instance.
 *
 * Returns 0 on success, -1 on failure.
 */

SPHIA_EXTERN int
sphia_rm (sphia_t *, const char *);

#ifdef __cplusplus
}
#endif
#endif
