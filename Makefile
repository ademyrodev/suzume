.DEFAULT_GOAL := debug

SRC := src/

CC := gcc
FILES := $(shell find $(SRC) -name '*.c')
CFLAGS := -Wall -Wextra -pedantic -Werror -Wconversion -Isrc/include/ -o test
LFLAGS := -lGL -lGLU -lglut

debug:
	@$(CC) $(FILES) $(CFLAGS) -g $(LFLAGS)
