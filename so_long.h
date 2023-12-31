/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:30:10 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/25 15:35:09 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1 
#  include <mlx.h>
#  include <stdio.h>
#  include <stdlib.h>
#  include <unistd.h>
#  include <fcntl.h>
/* Game objects */
#  define OPEN_SPACE '0'
#  define WALL '1'
#  define PLAYER 'P'
#  define EXIT 'E'
#  define COLLECTIBLE 'C'
/* Game sizes */
#  define IMG 32 
#  define ROW_MAX 42 
#  define COL_MAX 80 
/* Game keywords */
#  define W 13
#  define UP 126
#  define S 1
#  define DOWN 125
#  define A 0
#  define LEFT 123
#  define D 2
#  define RIGHT 124
#  define ESC 53
/* Bonus */
#  define COLOR 0xffffff
#  ifndef BONUS
#	define BONUS 0
#endif

typedef struct s_pos
{
	int	row;
	int	col;
}		t_pos;

typedef struct s_map
{
	char			*data;
	int				index;
	int				rows;
	int				cols;
	int				collectibles;
	int				exit;
	int				player;
	t_pos			player_pos;	
	t_pos			exit_pos;	
	struct s_map	*next;
}					t_map;

typedef struct s_cmap
{
	char	**fmap;
	int		collectibles;
	int		rows;
	int		cols;
	t_pos	player_pos;
	t_pos	exit_pos;
}				t_cmap;

typedef struct s_tiles
{
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collectible;
	void	*w_player;
	void	*s_player;
	void	*d_player;
	void	*a_player;
	void	*board;
}			t_tiles;

typedef struct s_game
{
	void	*conn;
	void	*win;
	t_tiles	tiles;
	int		moves;
	t_cmap	map;
}			t_game;

/*			--- so_long ---			*/
void	so_long_exec(char **argv);
t_cmap	init_game_map(t_map **map);
void	error_checker(t_map **map);
void	check_images(char *imagepath);
/*			--- basic ---			*/
void	create_connection(t_game *game);
void	update_map(t_game *game, int r, int c, int k);//, char **map);
int		close_game(t_game *game, char *str);
void	image_checker(void);
/*			--- flood_fill ---			*/
void	flood_fill(char **map, t_pos size, int row, int col);
int		can_reach(char **map, t_map **omap);
int		count_totalfound(char **map);
/* 			--- Split ---				*/
char	**ft_split(char const *s, char c);
char	**ft_freearray(char	**arr);
/* 			--- get_next_line ---		*/
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
/* 			--- get_next_line_utils ---		*/
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
/* 			--- lst_utils ---		*/
t_map	*lstlast(t_map *map);
int		mapsize(t_map *map);
void	free_map(t_map **map);
t_map	*create_row(char *row, int rownum);
void	insert_row(t_map **head, char *row, int rownum);
/* MAP */
/* 			--- map ---		*/
t_map	**create_map(char *mapfile);
/* --- LIST CHECKING ---*/
int		check_chars(t_map **map);
void	set_positions(t_map **map, t_map *row, int col);
int		check_walls(t_map **map);
int		check_col(t_map **map);
/* 			--- map_utils ---		*/
int		map_format(char *name, char *format);
int		accepted_chars(char c, t_map **map);
t_map	*get_row(t_map **map, int rownum);
char	**get_charmap(t_map **map);
void	ft_putnbr_fd(int n, int fd);
/*			--- moves --- 		*/
int		can_move(t_game *game, char **map, int r, int c);
int		move_up_down(t_game *game, char **map, int keycode);
int		move_left_right(t_game *game, char **map, int keycode);
int		moving(int keycode, t_game *game);
/*			 --- tiles ---				*/
void	set_img_ptr(t_game *game);
void	put_base_map(t_game *game, char **map);
void	insert_collectibles(t_game *game, char **map);
void	insert_exit(t_game *game);
void	insert_player(t_game *game, int r, int c, int keycode);
/*			 --- utils ---				*/
void	exit_error(char *err);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_dup(const char *s1);
/*			 --- ft_steps ---				*/
void	write_moves(t_game *game);
void	cc_images(void *conn, void **image, char *path);
/*			 --- bonus ---				*/
void	bonus_place_steps(t_game *game);

# endif
#endif
