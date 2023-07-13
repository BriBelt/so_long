/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:28:33 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/13 08:58:50 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img_ptr(t_game *game)
{
	cc_images(game->conn, &game->tiles.floor, "img/floor.xpm");
	cc_images(game->conn, &game->tiles.wall, "img/wall.xpm");
	cc_images(game->conn, &game->tiles.collectible, "img/collectible.xpm");
	cc_images(game->conn, &game->tiles.exit, "img/exit.xpm");
	cc_images(game->conn, &game->tiles.player, "img/s_player.xpm");
}

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
		while (map[r][c])
		{
			if (map[r][c] == WALL)
				tile = game->tiles.wall;
			else
				tile = game->tiles.floor;
			mlx_put_image_to_window(conn, win, tile, c * IMG, r * IMG);
			c++;
		}
		r++;
	}
}

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

void	insert_player(t_game *game, int r, int c)
{
	void	*conn;
	void	*win;

	conn = game->conn;
	win = game->win;
	mlx_put_image_to_window(conn, win, game->tiles. player, c * IMG, r * IMG);
}
