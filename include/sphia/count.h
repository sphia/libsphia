
/**
 * `count.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_COUNT_H
#define SPHIA_COUNT_H 1
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "sphia.h"

/**
 * Return the number of keys in the given `sphia`
 * instance, or -1 on failure.
 */

SPHIA_EXTERN int
sphia_count (sphia_t *);

#ifdef __cplusplus
}
#endif
#endif
