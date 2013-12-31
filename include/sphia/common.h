
/**
 * `common.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_COMMON_H
#define SPHIA_COMMON_H 1
#ifdef __cplusplus
extern "C" {
#endif

#if __GNUC__ >= 4
# define SPHIA_EXTERN __attribute__((visibility("default")))
#else
# define SPHIA_EXTERN
#endif

#ifdef __cplusplus
}
#endif
#endif
