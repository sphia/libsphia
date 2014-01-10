
CC ?= cc
CFLAGS ?= -std=c99 \
	-Wall \
	 -O2  \
	-fvisibility=hidden \
	-fPIC -pedantic

NAME ?= str-ends-with
OBJ = $(NAME).o
SRC = $(NAME).c

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(STATIC) $(OBJ)

.PHONY: clean
