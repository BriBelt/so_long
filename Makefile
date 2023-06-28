NAME = so_long

SRCS = basic.c

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror -g3 -fsanitize=address

%.o: %.c
		$(CC) $(CFLAGS) 
