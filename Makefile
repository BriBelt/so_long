NAME = so_long

BONUS_NAME = so_long_bonus

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
	   utils.c \
	   ft_itoa.c \
	   ft_steps.c 

BONUS_SRCS = bonus.c

OBJECTS = $(SRCS:.c=.o)

BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror

MLXFLAGS += -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(OBJECTS) $(BONUS_OBJECTS)  
	$(CC) $(CFLAGS) -D BONUS=1 $(SRCS) $(BONUS_SRCS) $(MLXFLAGS) -o $(BONUS_NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLXFLAGS) -o $(NAME) 

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS) 

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re 
