
#include <stdio.h>
#include <sphia.h>

#define error_and_exit() {                            \
  fprintf(stderr, "error: %s\n", sphia_error(sphia)); \
  exit(1);                                            \
}


int
main (void) {
  sphia_t *sphia = sphia_new(SPHIA_TEST_DB);
  if (NULL == sphia) error_and_exit();

  // set 100 key/value pairs, just for something to iterate
  for (int i = 0; i < 100; i++) {
    char *key = malloc(16);
    char *value = malloc(16);

    sprintf(key, "key%03d", i);
    sprintf(value, "value%03d", i);

    if (-1 == sphia_set(sphia, key, value)) error_and_exit();
  }

  // create our iterator
  sphia_iterator_t *iterator = sphia_iterator_new(sphia);
  if (NULL == iterator) error_and_exit();

  sphia_iterator_node_t *node;
  // loop until we hit the end
  while ((node = sphia_iterator_next(iterator))) {
    printf("%s =  '%s'\n", node->key, node->value);
    // cleanup the node
    sphia_iterator_node_free(node);
  }

  // close the iterator
  sphia_iterator_free(iterator);

  // close the db
  sphia_free(sphia);
  return 0;
}
