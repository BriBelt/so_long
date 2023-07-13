NAME = so_long

SRCS = basics.c \
	   flood_fill.c \
	   ft_split.c \
	   get_next_line.c \
	   get_next_line_utils.c \
	   lst_utils.c \
	   map.c \
	   map_utils.c \
	   moves.c \
	   so_long.c \
	   tiles.c \
	   utils.c

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror

MLXFLAGS += -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLXFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
