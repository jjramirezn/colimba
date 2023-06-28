CC := gcc-13
CFLAGS := -std=c90 -ansi -Wall -Wextra -pedantic

SRCS := $(wildcard *.c)

PROGS := $(patsubst %.c,build/%,$(SRCS))

all: $(PROGS)

build/%: %.c build
	$(CC) $(CFLAGS) -o $@ $<

build:
	mkdir build

.PHONY: clean
clean:
	rm -rf build
