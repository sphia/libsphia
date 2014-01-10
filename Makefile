PREFIX ?= /usr/local
DESTDIR ?= sphia

OS = $(shell uname)
CC ?= cc
AR = ar
LN = ln
RM = rm
VALGRIND ?= valgrind
STRIP = strip

LIB_NAME = sphia
VERSION_MAJOR = 0
VERSION_MINOR = 1

DEPS = $(test -d deps && shell ls deps/)
STATIC_DEPS = $(wildcard deps/*/*.a)

TARGET_NAME = lib$(LIB_NAME)
TARGET_STATIC = $(TARGET_NAME).a
TARGET_DSOLIB = $(TARGET_NAME).so.$(VERSION_MAJOR).$(VERSION_MINOR)
TARGET_DYLIB = $(TARGET_NAME).$(VERSION_MAJOR).$(VERSION_MINOR).dylib
TARGET_DSO = $(TARGET_NAME).so

CFLAGS += -Iinclude -Ideps    \
					-std=c99 -Wall -O2  \
					-fvisibility=hidden \
					-fPIC -pedantic

LDFLAGS += -shared   \
					 -lsophia  \
					 -lpthread \
					 -soname $(TARGET_DSO).$(VERSION_MAJOR)

OSX_LDFLAGS += -lc \
							 -Wl,-install_name,$(TARGET_DSO) \
							 -o $(TARGET_DSOLIB) \
							 -lsophia \
							 -lpthread

SRC = $(wildcard src/*.c)
SRC += $(STATIC_DEPS)
OBJS = $(SRC:.c=.o)

TEST_SRC = $(filter-out test/test.c, $(wildcard test/*.c))
TEST_OBJS = $(TEST_SRC:.c=.o)
TEST_MAIN = sphia-test
TEST_DB_PATH ?= /tmp/sphia-test-db

ifneq ("Darwin","$(OS)")
	CFLAGS += -lm
endif

ifdef DEBUG
	CFLAGS += -DSPHIA_DEBUG
endif

all: $(DEPS) $(TARGET_STATIC) $(TARGET_DSO)

$(TARGET_STATIC): $(OBJS)
	$(AR) crus $(TARGET_STATIC) $(OBJS)

$(TARGET_DSO): $(OBJS)
ifeq ("Darwin","$(OS)")
	$(CC) -shared $(OBJS) $(OSX_LDFLAGS) -o $(TARGET_DSOLIB)
	$(LN) -s $(TARGET_DSOLIB) $(TARGET_DSO)
	$(LN) -s $(TARGET_DSOLIB) $(TARGET_DSO).$(VERSION_MAJOR)
else
	$(CC) -shared $(OBJS) -o $(TARGET_DSOLIB)
	$(LN) -s $(TARGET_DSOLIB) $(TARGET_DSO)
	$(LN) -s $(TARGET_DSOLIB) $(TARGET_DSO).$(VERSION_MAJOR)
	$(STRIP) --strip-unneeded $(TARGET_DSO)
endif

src/.c.o:
	$(CC) $(CFLAGS) -c $<

test/.c.o:
	$(CC) $(CFLAGS) -c $<

$(DEPS):
	make -C deps/$@

check: test
	$(VALGRIND) --leak-check=full ./$(TEST_MAIN)

test: CFLAGS += -DSPHIA_TEST_DB='"$(TEST_DB_PATH)"'
test: $(TEST_OBJS) all
	$(CC) $(TEST_OBJS) test.c \
		$(STATIC_DEPS) ./$(TARGET_STATIC) \
		$(CFLAGS) -o $(TEST_MAIN) \
		-lsophia -lpthread
	./$(TEST_MAIN)

travis:
	rm -rf sophia
	git clone --depth=1 https://github.com/larzconwell/sophia.git sophia
	$(MAKE) -C sophia/db
	mv sophia/db sophia/sophia
	rm -f sophia/sophia/*.so*
	CFLAGS="-Isophia/" LIBRARY_PATH="./sophia/sophia" $(MAKE) test

clean:
	$(foreach dep,$(DEPS),$(shell make clean -C deps/$(dep)))
	$(RM) -f $(TEST_MAIN)
	$(RM) -f $(OBJS)
	$(RM) -f $(TEST_OBJS)
	$(RM) -f $(TARGET_STATIC)
	$(RM) -f $(TARGET_DSOLIB)
	$(RM) -f $(TARGET_DSO).$(VERSION_MAJOR)
	$(RM) -f $(TARGET_DSO)
	$(RM) -f $(TARGET_DYLIB)
	$(RM) -fr test-db sophia $(TEST_DB_PATH)

install: all
	test -d $(PREFIX)/$(DESTDIR) || mkdir $(PREFIX)/$(DESTDIR)
	install $(LIB_NAME).h $(PREFIX)/include
	cp include/$(LIB_NAME)/*.h $(PREFIX)/include/$(DESTDIR)
	install $(TARGET_STATIC) $(PREFIX)/lib
	install $(TARGET_DSO) $(PREFIX)/lib

uninstall:
	rm -rf $(PREFIX)/$(DESTDIR)
	rm -f $(PREFIX)/lib/$(TARGET_STATIC)
	rm -f $(PREFIX)/lib/$(TARGET_DSO)

.PHONY: test
