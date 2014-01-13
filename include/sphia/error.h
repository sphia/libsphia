
/**
 * `error.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_ERROR_H
#define SPHIA_ERROR_H 1
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "sphia.h"

/**
 * Get the last known error on the `sphia`
 * instance.
 */

SPHIA_EXTERN char *
sphia_error (sphia_t *);

#ifdef __cplusplus
}
#endif
#endif
