/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:28:33 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/04 12:16:30 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game.conn = mlx_init();
	game.win = mlx_new_window(
}
void	create_all_images(t_game *game)
{
	check_image(game, &game->tiles.floor, "game_img/floor.xpm");
	check_image(game, &game->tiles.wall, "game_img/wall.xpm"); 
	check_image(game, &game->tiles.exit, "game_img/exit.xpm"); 
	check_image(game, &game->tiles.collectible, "game_img/collectible.xpm"); 
	check_image(game, &game->tiles.player, "game_img/player.xpm");
}

void	check_image(t_game *game, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_to_image(game.conn, path, &width, &height);
	if (*image == NULL)
		exit_error("Could not find the image");
}

