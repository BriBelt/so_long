/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:47:55 by bbeltran          #+#    #+#             */
/*   Updated: 2023/08/05 14:51:53 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* As its name says so, this function will create the connection for both
 * the system and the window, then place the maptiles accordingly to the
 * array map (calling update_map function). Next we call the mlx_hook
 * functions for closing the game (when clicking on the 'X') and the mlx_hook
 * function in charge of actually doing the movements.*/
void	create_connection(t_game *game)
{
	game->conn = mlx_init();
	game->win = mlx_new_window(game->conn, game->map.cols * IMG,
			game->map.rows * IMG, "so_long");
	put_base_map(game, game->map.fmap);
	insert_collectibles(game, game->map.fmap);
	insert_player(game, game->map.player_pos.row, game->map.player_pos.col, S);
	mlx_hook(game->win, 17, 0, (void *)exit, 0);
	mlx_hook(game->win, 2, 1L << 0, moving, game);
	mlx_loop(game->conn);
}

/* This just calls other functions that place the required tiles (player,
 * exit, collectibles, floor, and walls). Also checks if the number of 
 * collectibles is 0 it will call the insert_exit function to put or
 * make the exit visible. */
void	update_map(t_game *game, int r, int c, int k)
{
	void	*tile;
	void	*win;
	void	*conn;

	win = game->win;
	conn = game->conn;
	tile = game->tiles.floor;
	mlx_put_image_to_window(conn, win, tile, c * IMG, r * IMG);
	insert_player(game, game->map.player_pos.row, game->map.player_pos.col, k);
	if (game->map.collectibles == 0)
		insert_exit(game);
}

/* This will close the game if called, it will first put a string
 * (if passed), next, it will destroy the window and free our map array. */
int	close_game(t_game *game, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	mlx_destroy_window(game->conn, game->win);
	ft_freearray(game->map.fmap);
	exit(0);
}

void	image_checker(void)
{
	check_images("img/floor.xpm");
	check_images("img/wall.xpm");
	check_images("img/collectible.xpm");
	check_images("img/exit.xpm");
	check_images("img/s_player.xpm");
	check_images("img/w_player.xpm");
	check_images("img/d_player.xpm");
	check_images("img/a_player.xpm");
}
