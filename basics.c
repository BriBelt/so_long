/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:47:55 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/13 09:00:17 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_connection(t_game *game)
{
	game->conn = mlx_init();
	game->win = mlx_new_window(game->conn, game->map.cols * IMG,
			game->map.rows * IMG, "so_long");
	update_map(game, game->map.fmap);
	mlx_hook(game->win, 17, 0L, close_game, game);
	mlx_hook(game->win, 2, 1L << 0, moving, game);
	mlx_loop(game->conn);
}

void	update_map(t_game *game, char **map)
{
	put_base_map(game, map);
	insert_collectibles(game, map);
	insert_player(game, game->map.player_pos.row, game->map.player_pos.col);
	if (game->map.collectibles == 0)
		insert_exit(game);
}

int	close_game(t_game *game, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	mlx_destroy_window(game->conn, game->win);
	ft_freearray(game->map.fmap);
	exit(0);
	return (0);
}
