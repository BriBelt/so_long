/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:47:55 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/11 12:09:51 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_connection(t_map **map, t_game *game, char **cmap)
{
	game->conn = mlx_init();
	game->win = mlx_new_window(game->conn, (*map)->cols * IMG,
			(*map)->rows * IMG, "so_long");
	insert_tiles(game, cmap); 
	insert_others(cmap, game);
	mlx_loop(game->conn);
}
