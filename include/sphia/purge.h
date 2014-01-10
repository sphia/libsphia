
/**
 * `purge.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_PURGE_H
#define SPHIA_PURGE_H 1
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "sphia.h"

/**
 * Purge the given `sphia` instance of corrupt
 * and incomplete data.
 *
 * Return 0 on success, -1 on error.
 */

SPHIA_EXTERN int
sphia_purge (sphia_t *);


#ifdef __cplusplus
}
#endif
#endif
