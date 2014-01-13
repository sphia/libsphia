
/**
 * `purge.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sophia/sp.h>
#include <sophia/sophia.h>
#include <sphia/common.h>
#include <sphia/purge.h>
#include <str-ends-with/str-ends-with.h>

int
sphia_purge (sphia_t *self) {
  if (NULL == self) return -1;

  DIR *dir = opendir(self->path);
  struct dirent *fd = NULL;

  while ((fd = readdir(dir))) {
    if (('.' == fd->d_name[0]) || (str_ends_with(fd->d_name, ".log"))) {
      continue;
    }

    char *path = malloc(256);
    if (NULL == path) {
      closedir(dir);
      return -1;
    }

    sprintf(path, "%s/%s", self->path, fd->d_name);

    if (-1 == unlink(path)) {
      free(path);
      closedir(dir);
      return -1;
    }

    free(path);
  }

  closedir(dir);
  return 0;
}
