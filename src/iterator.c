
/**
 * `iterator.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <string.h>
#include <sophia.h>
#include <sphia/common.h>
#include <sphia/iterator.h>

sphia_iterator_t *
sphia_iterator_new (sphia_t *self) {
  if (NULL == self) return NULL;

  void *cursor = NULL;
  sphia_iterator_t *iterator;
  if (!(iterator = malloc(sizeof(sphia_iterator_t))))
    return NULL;

  memset(iterator, '\0', sizeof(sphia_iterator_t));

  if (!(cursor = sp_cursor(self->db, SPGT, NULL, 0))) {
    free(iterator);
    return NULL;
  }

  iterator->cursor = cursor;
  iterator->direction = SPGT;
  iterator->db = self->db;
  iterator->last_key = NULL;
  iterator->last_keysize = 0;

  return iterator;
}

sphia_iterator_node_t *
sphia_iterator_next (sphia_iterator_t *self) {
  sphia_iterator_node_t *node = NULL;
  size_t keysize = 0;
  size_t valuesize = 0;
  const char *key = NULL;
  const char *value = NULL;

  if (NULL == self->cursor) {
    self->cursor = sp_cursor(self->db
      , self->direction
      , self->last_key
      , self->last_keysize);
    if (NULL == self->cursor) return NULL;
  }

  if (0 == sp_fetch(self->cursor)) return NULL;

  if (!(node = malloc(sizeof(sphia_iterator_node_t))))
    return NULL;

  node->key = NULL;
  node->value = NULL;

  if (!(key = sp_key(self->cursor)) || !(value = sp_value(self->cursor))) {
    free(node);
    return NULL;
  }

  keysize = sp_keysize(self->cursor);
  valuesize = sp_valuesize(self->cursor);

  // record so we can create a
  // cursor at this position
  self->last_key = key;
  self->last_keysize = keysize;

  if (!(node->key = sphia_strdup(key))
    || !(node->value = sphia_strdup(value))) {
    sphia_iterator_node_free(node);
    return NULL;
  }

  if ('\0' != node->key[keysize])
    node->key[keysize] = '\0';

  if ('\0' != node->value[valuesize])
    node->value[valuesize] = '\0';

  return node;
}

int
sphia_iterator_direction (sphia_iterator_t *self, sporder direction) {
  if (NULL == self) return -1;
  if (direction == self->direction) return 0;

  // can't change the direction of an active
  // cursor, so we need to close it first
  if (self->cursor) sphia_iterator_end(self);

  self->cursor = sp_cursor(self->db
    , direction
    , self->last_key
    , self->last_keysize);

  if (self->cursor) {
    self->direction = direction;
    return 0;
  }

  return -1;
}

void
sphia_iterator_end (sphia_iterator_t *self) {
  if (self->cursor) sp_destroy(self->cursor);
  self->cursor = NULL;
}

void
sphia_iterator_node_free (sphia_iterator_node_t *node) {
  if (node->key) free(node->key);
  if (node->value) free(node->value);
  free(node);
}

void
sphia_iterator_free (sphia_iterator_t *self) {
  if (self->cursor) sp_destroy(self->cursor);
  free(self);
}
