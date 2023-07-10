/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:28:33 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/08 18:40:46 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	cc_images(void *conn, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(conn, path, &width, &height);
	if (*image == NULL)
		exit_error("Could not find the image");
}

void	set_img_ptr(t_game *game)
{
	cc_images(game->conn, &game->tiles.floor, "img/floor.xpm");
	cc_images(game->conn, &game->tiles.wall, "img/wall.xpm");
	cc_images(game->conn, &game->tiles.collectible, "img/collectible.xpm");
	cc_images(game->conn, &game->tiles.exit, "img/exit.xpm");
}

void	insert_tiles(t_game *game, char **map)
{
	int		r;
	int		c;
	void	*conn;
	void	*win;
	t_tiles	*tile;

	r = 0;
	c = 0;
	conn = game->conn;
	win = game->win;
	set_img_ptr(game);
	while (map[r])
	{
		while (map[r][c])
		{
			tile = which_tile(map[r][c], game);
			mlx_put_image_to_window(conn, win, tile, r * IMG, c * IMG);
			c++;
		}
		r++;
	}
}

t_tiles	*which_tile(char c, t_game *game)
{
	if (c == OPEN_SPACE)
		return (game->tiles.floor);
	if (c == WALL)
		return (game->tiles.wall);
	if (c == EXIT)
		return (game->tiles.exit);
	if (c == PLAYER)
		return (game->tiles.player);
	if (c == COLLECTIBLE)
		return (game->tiles.collectible);
	return (NULL);
}
