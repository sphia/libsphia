
/**
 * `clear.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_CLEAR_H
#define SPHIA_CLEAR_H 1
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "sphia.h"

/**
 * Remove all keys from the given `sphia` instance.
 *
 * Returns 0 on success, -1 on failure.
 */

SPHIA_EXTERN int
sphia_clear (sphia_t *);

#ifdef __cplusplus
}
#endif
#endif
