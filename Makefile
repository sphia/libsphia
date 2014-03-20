
CC ?= gcc
AR ?= ar
LN ?= ln
RM ?= rm
VALGRIND ?= valgrind
STRIP ?= strip

OS = $(shell uname)

PREFIX ?= /usr/local
DESTDIR ?= sphia

LIB_NAME = sphia
VERSION_MAJOR = 0
VERSION_MINOR = 0
TARGET_NAME = lib$(LIB_NAME)
TARGET_STATIC = $(TARGET_NAME).a
TARGET_DSO = $(TARGET_NAME).so
TARGET_DSOLIB = $(TARGET_DSO).$(VERSION_MAJOR).$(VERSION_MINOR)
TARGET_DYLIB = $(TARGET_NAME).$(VERSION_MAJOR).$(VERSION_MINOR).dylib

DEPS = $(wildcard deps/*/*.c)
DEP_OBJS = $(DEPS:.c=.o)

SRC = $(wildcard src/*.c)
OBJS = $(SRC:.c=.o)

TESTS = test.c $(filter-out test/test.c, $(wildcard test/*.c))
TEST_OBJS = $(TESTS:.c=.o)
TEST_MAIN = sphia-test
TEST_DB_PATH ?= /tmp/sphia-test-db

EXAMPLES = $(wildcard examples/*.c)
EXAMPLE_OBJS = $(EXAMPLES:.c=.o)
EXAMPLE_BINS = $(EXAMPLES:.c=)

CFLAGS += -Iinclude -Ideps \
          -std=c99 -Wall -O2 \
          -fvisibility=hidden \
          -fPIC -pedantic
TEST_CFLAGS = -DSPHIA_TEST_DB='"$(TEST_DB_PATH)"'

LDFLAGS += -o $(TARGET_DSOLIB) -lsophia -lpthread -shared
TEST_LDFLAGS = -lsophia -lpthread

ifeq ($(OS), Darwin)
	LDFLAGS += -lc -Wl,-install_name,$(TARGET_DSO)
endif

all: $(TARGET_STATIC) $(TARGET_DSO)

$(TARGET_STATIC): $(DEP_OBJS) $(OBJS)
	$(AR) crus $@ $^

$(TARGET_DSO): $(DEP_OBJS) $(OBJS)
	$(CC) $^ -o $(TARGET_DSOLIB) $(LDFLAGS)
	$(LN) -s $(TARGET_DSOLIB) $@
	$(LN) -s $(TARGET_DSOLIB) $@.$(VERSION_MAJOR)
ifeq ($(OS), Linux)
	$(STRIP) --strip-unneeded $@
endif

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

test: $(TEST_MAIN)
	./$(TEST_MAIN)

check: $(TEST_MAIN)
	$(VALGRIND) --leak-check=full ./$^

$(TEST_MAIN): CFLAGS += $(TEST_CFLAGS)
$(TEST_MAIN): $(TEST_OBJS) $(TARGET_STATIC)
	$(CC) $^ -o $@ $(CFLAGS) $(TEST_LDFLAGS)

travis:
	rm -rf sophia
	git clone --depth=1 https://github.com/pmwkaa/sophia.git sophia
	$(MAKE) -C sophia/db
	rm -f sophia/db/*.so*
	CFLAGS="-Isophia/db" LIBRARY_PATH="./sophia/db" $(MAKE) test

examples: CFLAGS += $(TEST_CFLAGS)
examples: $(TARGET_STATIC) $(EXAMPLE_OBJS) $(EXAMPLE_BINS)

$(EXAMPLE_BINS):
	$(CC) ./$(TARGET_STATIC) $@.o -o $@ $(TEST_LDFLAGS)

install: all
	mkdir -p $(PREFIX)/include/$(DESTDIR)
	install ./include/$(LIB_NAME).h $(PREFIX)/include
	cp ./include/$(LIB_NAME)/*.h $(PREFIX)/include/$(DESTDIR)
	install $(TARGET_STATIC) $(PREFIX)/lib
	install $(TARGET_DSO) $(PREFIX)/lib

uninstall:
	rm -rf $(PREFIX)/include/$(DESTDIR)
	rm -f $(PREFIX)/lib/$(TARGET_STATIC)
	rm -f $(PREFIX)/lib/$(TARGET_DSO)

clean:
	$(RM) $(DEP_OBJS) $(OBJS) $(TEST_OBJS) $(EXAMPLE_OBJS)
	$(RM) $(TEST_MAIN) $(EXAMPLE_BINS)
	$(RM) $(TARGET_NAME).*
	$(RM) -rf $(TEST_DB_PATH)

.PHONY: clean test check examples
