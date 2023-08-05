/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:12:35 by bbeltran          #+#    #+#             */
/*   Updated: 2023/08/05 14:24:30 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bonus_place_steps(t_game *game)
{
	char	*moves;
	void	*conn;
	void	*win;
	void	*tile;

	if (BONUS == 1)
	{
		conn = game->conn;
		win = game->win;
		tile = game->tiles.wall;
		moves = ft_itoa(game->moves);
		mlx_put_image_to_window(conn, win, tile, 0 * IMG, 0 * IMG);
		mlx_string_put(conn, win, 0.35 * IMG, 0.06 * IMG, COLOR, moves);
		free(moves);
	}
}
