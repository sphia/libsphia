
/**
 * `test/iterator.c' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#include <stdlib.h>
#include <string.h>
#include <sophia.h>
#include <sphia/sphia.h>
#include <sphia/new.h>
#include <sphia/free.h>
#include <sphia/set.h>
#include <sphia/get.h>
#include <sphia/iterator.h>
#include <sphia/clear.h>
#include <sphia/test.h>

TEST(simple_iterator);
TEST(iterator_stop_next);
TEST(iterator_backwards);
TEST(iterator_direction);

TEST(iterator) {
  HEADER(sphia_iterator);
  RUN(simple_iterator);
  RUN(iterator_stop_next);
  RUN(iterator_backwards);
  RUN(iterator_direction);
  FOOTER();
}

TEST(simple_iterator) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);

  // let's start fresh :)
  assert(0 == sphia_clear(sphia));

  int count = 2000;

  for (int i = 0; i < count; i++) {
    char *key = malloc(8);
    sprintf(key, "key%04d", i);
    assert(0 == sphia_set(sphia, key, "value"));
    free(key);
  }

  sphia_iterator_t *iterator = sphia_iterator_new(sphia);
  assert(iterator);

  for (int i = 0; i < count; i++) {
    sphia_iterator_node_t *node = sphia_iterator_next(iterator);
    assert(node);
    char *key = malloc(8);
    sprintf(key, "key%04d", i);
    assert(0 == strcmp(node->key, key));
    assert(0 == strcmp(node->value, "value"));
    free(key);
    sphia_iterator_node_free(node);
  }

  assert(NULL == sphia_iterator_next(iterator));

  sphia_iterator_free(iterator);

  sphia_free(sphia);
  return 0;
}

TEST(iterator_stop_next) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);
  assert(0 == sphia_clear(sphia));

  assert(0 == sphia_set(sphia, "a", "123"));
  assert(0 == sphia_set(sphia, "b", "456"));
  assert(0 == sphia_set(sphia, "c", "789"));

  sphia_iterator_t *iterator = sphia_iterator_new(sphia);
  assert(iterator);

  sphia_iterator_node_t *node;

  node = sphia_iterator_next(iterator);
  assert(node);
  assert(0 == strcmp(node->key, "a"));
  assert(0 == strcmp(node->value, "123"));
  sphia_iterator_node_free(node);

  sphia_iterator_end(iterator);
  assert(NULL == iterator->cursor);

  node = sphia_iterator_next(iterator);
  assert(node);

  assert(0 == strcmp(node->key, "b"));
  assert(0 == strcmp(node->value, "456"));
  sphia_iterator_node_free(node);

  node = sphia_iterator_next(iterator);
  assert(node);
  assert(0 == strcmp(node->key, "c"));
  assert(0 == strcmp(node->value, "789"));
  sphia_iterator_node_free(node);

  assert(NULL == sphia_iterator_next(iterator));

  sphia_iterator_free(iterator);
  sphia_free(sphia);
  return 0;
}

TEST(iterator_backwards) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);
  assert(0 == sphia_clear(sphia));

  assert(0 == sphia_set(sphia, "a", "123"));
  assert(0 == sphia_set(sphia, "b", "456"));
  assert(0 == sphia_set(sphia, "c", "789"));

  sphia_iterator_t *iterator = sphia_iterator_new(sphia);
  assert(iterator);

  assert(0 == sphia_iterator_direction(iterator, SPLT));
  assert(SPLT == iterator->direction);

  sphia_iterator_node_t *node;

  node = sphia_iterator_next(iterator);
  assert(node);
  assert(0 == strcmp(node->key, "c"));
  assert(0 == strcmp(node->value, "789"));
  sphia_iterator_node_free(node);

  sphia_iterator_end(iterator);
  assert(NULL == iterator->cursor);

  node = sphia_iterator_next(iterator);
  assert(node);

  assert(0 == strcmp(node->key, "b"));
  assert(0 == strcmp(node->value, "456"));
  sphia_iterator_node_free(node);

  node = sphia_iterator_next(iterator);
  assert(node);
  assert(0 == strcmp(node->key, "a"));
  assert(0 == strcmp(node->value, "123"));
  sphia_iterator_node_free(node);

  assert(NULL == sphia_iterator_next(iterator));

  sphia_iterator_free(iterator);
  sphia_free(sphia);
  return 0;
}

TEST(iterator_direction) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  assert(sphia);
  assert(0 == sphia_clear(sphia));

  sphia_iterator_t *iterator = sphia_iterator_new(sphia);
  assert(iterator);
  assert(SPGT == iterator->direction);

  assert(0 == sphia_iterator_direction(iterator, SPLT));
  assert(SPLT == iterator->direction);

  sphia_iterator_free(iterator);
  sphia_free(sphia);
  return 0;
}
