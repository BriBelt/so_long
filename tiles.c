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
void	create_images(t_game *game)
{
	int	width;
	int	height;

	game->tiles.floor = mlx_xpm_file_to_image(game->conn, "img/floor.xpm", &width, &height);
	mlx_put_image_to_window(game->conn, game->win, game->tiles.floor, 0, 0);
}

void	check_image(t_game *game, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_to_image(game->conn, &path, &width, &height);
	if (*image == NULL)
		exit_error("Could not find the image");
}
/*void	create_all_images(t_game *game)
{
	game->tiles.floor = mlx_new_image(game->conn, IMG_SIZE, IMG_SIZE);
	check_image(game, &game->tiles.floor, "./img/floor.xpm");
//	check_image(game, &game->tiles.wall, "img/wall.xpm"); 
//	check_image(game, &game->tiles.exit, "img/exit.xpm"); check_image(game, &game->tiles.collectible, "game_img/collectible.xpm"); 
//	check_image(game, &game->tiles.player, "img/player.xpm");
}*/
