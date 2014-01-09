
/**
 * `free.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_FREE_H
#define SPHIA_FREE_H 1
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "sphia.h"

/**
 * Free memory from the given `sphia` instance.
 */

SPHIA_EXTERN void
sphia_free(sphia_t *);

#ifdef __cplusplus
}
#endif
#endif
