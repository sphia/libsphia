
/**
 * `common.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <string.h>
#include <sphia/common.h>

char *
sphia_strdup (const char *str) {
  int len = strlen(str) + 1;
  char *buf = malloc(len);
  if (NULL == buf) return NULL;
  memcpy(buf, str, len);
  return buf;
}
