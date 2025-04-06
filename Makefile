CC := gcc
CFLAGS := -Wall -Werror -pedantic -ansi -std=c99
SRCS := game.c
EXEC := game

all: $(EXEC)

clean:
	@rm game
