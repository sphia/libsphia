# libsphia

  Higher level API for working with SophiaDB

  [![Build Status](https://travis-ci.org/sphia/libsphia.png)](https://travis-ci.org/sphia/libsphia)

## API

### sphia_t *sphia_new(const char *path)

  Create/open a Sophia database at `path`.

  Returns NULL on failure.

### int sphia_count(sphia_t *sphia)

  Return the number of keys in the given `sphia` instance, or -1 on failure.

### void sphia_free(sphia_t *sphia)

  Free memory from the given `sphia` instance.

### char *sphia_get(sphia_t *sphia, const char *key)

  Get the value of `key` in the given `sphia` instance.  The returned value will always be NUL terminated.

  Returns NULL on error.

### int sphia_rm(sphia_t *sphia, const char *key)

  Remove `key` from the given `sphia` instance.

  Returns 0 on success, -1 on failure.

### int sphia_set(sphia_t *sphia, const char *key, const char *value)

  Set `key=value` in the given `sphia` instance.

  Returns 0 on success, -1 on failure.