
/**
 * `new.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_NEW_H
#define SPHIA_NEW_H 1
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "sphia.h"

/**
 * Create/open a Sophia database at `path`.
 *
 * Returns NULL on failure.
 */

SPHIA_EXTERN sphia_t *
sphia_new(const char *);

#ifdef __cplusplus
}
#endif
#endif
