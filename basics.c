/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:47:55 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/11 16:16:34 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_connection(t_game *game)
{
	game->conn = mlx_init();
	game->win = mlx_new_window(game->conn, game->map.cols * IMG,
			game->map.rows * IMG, "so_long");
	insert_tiles(game, game->map.fmap); 
	insert_others(game, game->map.fmap); 
	mlx_loop(game->conn);
}
