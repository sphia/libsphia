
/**
 * `test/tests.h' - libsphia
 *
 * Copyright (C) 2014 The libsphia Authors <sphia@googlegroups.com>
 */

#ifndef SPHIA_TESTS_H
#define SPHIA_TESTS_H 1

#include <stdio.h>
#include <assert.h>

#define HEADER(n) \
  printf("\n[running '%s' tests]\n\n", #n)

#define FOOTER()                            \
  printf("\n--\n");                         \
  printf("  passed: (%d)\n", TESTS_PASSED); \
  printf("  failed: (%d)\n", TESTS_FAILED); \
  printf("--\n");                           \
  return (TESTS_FAILED > 0) ? 1 : 0

#define RUN(n)                              \
  if (0 != test_## n()) {                   \
    TESTS_FAILED++;                         \
    fprintf(stderr, "  (x) %s fail\n", #n); \
  } else {                                  \
    TESTS_PASSED++;                         \
    printf("  (✓) %s pass\n", #n);          \
  }

#define THROW(str) fprintf(stderr, str); exit(1);
#define TEST(n) int test_## n ()

/**
 * A list of all the test to run
 */

#endif
