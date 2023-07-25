/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:28:33 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/25 13:03:07 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Sets the pointer for all the previously checked images by calling the
 * cc_images function. */
void	set_img_ptr(t_game *game)
{
	cc_images(game->conn, &game->tiles.floor, "img/floor.xpm");
	cc_images(game->conn, &game->tiles.wall, "img/wall.xpm");
	cc_images(game->conn, &game->tiles.collectible, "img/collectible.xpm");
	cc_images(game->conn, &game->tiles.exit, "img/exit.xpm");
	cc_images(game->conn, &game->tiles.s_player, "img/s_player.xpm");
	cc_images(game->conn, &game->tiles.w_player, "img/w_player.xpm");
	cc_images(game->conn, &game->tiles.a_player, "img/a_player.xpm");
	cc_images(game->conn, &game->tiles.d_player, "img/d_player.xpm");
	cc_images(game->conn, &game->tiles.board, "img/board.xpm");
}

/* Will first call the set_img_ptr to get the corresponding pointer
 * for each image, and later place each floor and wall tile according to
 * the map array. */
void	put_base_map(t_game *game, char **map)
{
	int		r;
	int		c;
	void	*conn;
	void	*win;
	t_tiles	*tile;

	r = 0;
	conn = game->conn;
	win = game->win;
	set_img_ptr(game);
	while (r < game->map.rows)
	{
		c = 0;
		while (c < game->map.cols)
		{
			if (map[r][c] == WALL || map[r][c] == '\0')
				tile = game->tiles.wall;
			else
				tile = game->tiles.floor;
			mlx_put_image_to_window(conn, win, tile, c * IMG, r * IMG);
			c++;
		}
		r++;
	}
}

/* Will place all the collectibles inside the map accordingly to the
 * char **map. */
void	insert_collectibles(t_game *game, char **map)
{
	int		r;
	int		c;
	void	*conn;
	void	*win;
	t_tiles	*tile;

	r = 0;
	conn = game->conn;
	win = game->win;
	while (r < game->map.rows)
	{
		c = 0;
		while (map[r][c])
		{
			if (map[r][c] == COLLECTIBLE)
			{
				tile = game->tiles.collectible;
				mlx_put_image_to_window(conn, win, tile, c * IMG, r * IMG);
			}
			c++;
		}
		r++;
	}
}

/* Will make the exit tile visible with the previously saved exit position.*/
void	insert_exit(t_game *game)
{
	t_tiles	*tile;
	void	*conn;
	void	*win;
	int		r;
	int		c;

	conn = game->conn;
	win = game->win;
	r = game->map.exit_pos.row;
	c = game->map.exit_pos.col;
	tile = game->tiles.exit;
	mlx_put_image_to_window(conn, win, tile, c * IMG, r * IMG);
}

/* Will put the player image inside the map with the given position
 * (int r, int c). */
void	insert_player(t_game *game, int r, int c, int keycode)
{
	void	*conn;
	void	*win;
	void	*tile;

	conn = game->conn;
	win = game->win;
	if (keycode == W || keycode == UP)
		tile = game->tiles.w_player;
	if (keycode == S || keycode == DOWN)
		tile = game->tiles.s_player;
	if (keycode == A || keycode == LEFT)
		tile = game->tiles.a_player;
	if (keycode == D || keycode == RIGHT)
		tile = game->tiles.d_player;
	mlx_put_image_to_window(conn, win, tile, c * IMG, r * IMG);
}
