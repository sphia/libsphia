
/**
 * `iterator.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_ITERATOR_H
#define SPHIA_ITERATOR_H 1
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "sphia.h"

typedef struct {

  /**
   * Node key.
   */

  char *key;

  /**
   * Node value.
   */

  char *value;

} sphia_iterator_node_t;

typedef struct {

  /**
   * Cursor for the iterator.
   */

  void *cursor;

  /**
   * Iterator direction.  Can be `SPGT` or `SPLT`.
   */

  sporder direction;

  /**
   * Private.  Last key ref.
   */

  const char *last_key;

  /**
   * Private.  Last key size ref.
   */

  size_t last_keysize;

  /**
   * Private.  `db` ref.
   */

  void *db;

} sphia_iterator_t;

/**
 * Create a new iterator for the `sphia` instance.
 *
 * Transactions (writes, deletes, etc.) may not
 * occur while an iterator is open.
 */

SPHIA_EXTERN sphia_iterator_t *
sphia_iterator_new (sphia_t *);

/**
 * Get the next key/value pair from the given
 * `iterator`.
 *
 * If the `iterator` is stopped, will start it
 * in its last position.
 */

SPHIA_EXTERN sphia_iterator_node_t *
sphia_iterator_next (sphia_iterator_t *);

/**
 * Stop the given `iterator`.
 *
 * Once stopped, writes may occur.
 */

SPHIA_EXTERN void
sphia_iterator_end (sphia_iterator_t *);

/**
 * Set/change the `direction` of the given `iterator`.
 *
 * Returns -1 on failure, 0 on success.
 */

SPHIA_EXTERN int
sphia_iterator_direction (sphia_iterator_t *, sporder);

/**
 * Cleanup memory from the given iterator `node`.
 */

SPHIA_EXTERN void
sphia_iterator_node_free (sphia_iterator_node_t *);

/**
 * Cleanup memory from the given `iterator`.
 */

SPHIA_EXTERN void
sphia_iterator_free (sphia_iterator_t *);

#ifdef __cplusplus
}
#endif
#endif
