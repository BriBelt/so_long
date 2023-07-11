/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:30:10 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/11 12:09:32 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1 
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/* Game objects */
# define OPEN_SPACE '0'
# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define IMG 32 
/* Game keywords */
# define W
# define UP 
# define S
# define DOWN 
# define A
# define LEFT
# define D
# define RIGHT 
# define ESC 

typedef struct	s_pos
{
	int	row;
	int	col;
}		t_pos;

typedef struct	s_map
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
	struct	s_map	*next;
}					t_map;

typedef struct	s_tiles
{
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collectible;
	void	*player;
}			t_tiles;

typedef struct	s_game
{
	void	*conn;
	void	*win;
	t_tiles	tiles;
	int		moves;
}			t_game;

void	so_long_exec(char **argv);
/* lst_utils */
t_map	*create_row(char *row, int rownum);
void	insert_row(t_map **head, char *row, int rownum);
t_map 	*lstlast(t_map *map);
int		mapsize(t_map *map);
void	free_map(t_map **map);
/* MAP */
/* --- LIST(MAP) CREATION ---*/
t_map	**create_map(char *mapfile);
/* --- LIST CHECKING ---*/
int		check_chars(t_map **map);
void	set_positions(t_map **map, t_map *row, int col);
int		check_walls(t_map **map);
/* MAP_UTILS */
char	**get_charmap(t_map **map);
int		map_format(char *name, char *format);
int		accepted_chars(char c, t_map **map);
t_map	*get_row(t_map **map, int rownum);
void	flood_fill(char **map, t_pos size, int row, int col, int *total);
int		can_reach(char **map, t_map **omap);
//void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	exit_error(char *err);
/* CONNECTION */
void	create_connection(t_map **map, t_game *game, char **cmap);
/* GRAPHICS */
void		cc_images(void *conn, void **image, char *path);
void		set_img_ptr(t_game *game);
/* tiles */
void		insert_tiles(t_game *game, char **map);
void		insert_others(char **map, t_game *game);
t_tiles		*which_tile(char c, t_game *game);
/* GNL */
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char	*dst, const char *src, size_t siz);
char		*ft_strchr(const char *str, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
/* Split */
char	**ft_split(char const *s, char c);
char	*ft_dup(const char *s1);

#endif
#endif
