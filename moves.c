/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:28:27 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/12 19:23:12 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_game *game, char **map, int r, int c)
{
	if (r == game->map.exit_pos.row && c == game->map.exit_pos.col)
	{
		if (game->map.collectibles == 0)
			close_game(game, "Congratulations, you won!");
		map[r][c] = PLAYER;
		game->map.player_pos.row = r;
		game->map.player_pos.col = c;
		game->moves++;
	}
	if (map[r][c] == OPEN_SPACE)
	{
		map[r][c] = PLAYER;
		game->map.player_pos.row = r;
		game->map.player_pos.col = c;
		game->moves++;
	}
	if (map[r][c] == COLLECTIBLE)
	{
		map[r][c] = PLAYER;
		game->map.player_pos.row = r;
		game->map.player_pos.col = c;
		game->moves++;
		game->map.collectibles--;
	}
	return (1);
}

int	move_up_down(t_game *game, char **map, int keycode)
{
	int	r;
	int	c;

	r = game->map.player_pos.row;
	c = game->map.player_pos.col;
	if (keycode == DOWN || keycode == S)
	{
		r++;
		if (map[r][c] == WALL)
			return (0);
		if (!can_move(game, map, r, c))
			return (0);
		map[r - 1][c] = OPEN_SPACE;
	}
	else if (keycode == UP || keycode == W)
	{
		r--;
		if (map[r][c] == WALL)
			return (0);
		if (!can_move(game, map, r, c))
			return (0);
		map[r + 1][c] = OPEN_SPACE;
	}
	printf("---%i steps---\n", game->moves);
	return (1);
}

int	move_left_right(t_game *game, char **map, int keycode)
{
	int	r;
	int	c;

	r = game->map.player_pos.row;
	c = game->map.player_pos.col;
	if (keycode == LEFT || keycode == A)
	{
		c--;
		if (map[r][c] == WALL)
			return (0);
		if (!can_move(game, map, r, c))
			return (0);
		map[r][c + 1] = OPEN_SPACE;
	}
	else if (keycode == RIGHT || keycode == D)
	{
		c++;
		if (map[r][c] == WALL)
			return (0);
		if (!can_move(game, map, r, c))
			return (0);
		map[r][c - 1] = OPEN_SPACE;
	}
	printf("---%i steps---\n", game->moves);
	return (1);
}

int	moving(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game, 0);
	else if (keycode == UP || keycode == W)
		move_up_down(game, game->map.fmap, keycode);
	else if (keycode == DOWN || keycode == S)
		move_up_down(game, game->map.fmap, keycode);
	else if (keycode == LEFT || keycode == A)
		move_left_right(game, game->map.fmap, keycode);
	else if (keycode == RIGHT || keycode == D)
		move_left_right(game, game->map.fmap, keycode);
	update_map(game, game->map.fmap);
	return (0);
}
