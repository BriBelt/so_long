/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:28:27 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/25 18:11:02 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checks if the given position (r, c) is valid (OPEN_SPACE, COLLECTIBLE, EXIT)
 * In the case that the given position char is equal to EXIT and the number of
 * collectibles is 0, the game will end, if not, the player will be able to go
 * through the exit tile. If the map[r][c] is an OPEN_SPACE the player's
 * position will change and the number of moves will go up. If the map[r][c]
 * is a COLLECTIBLE the player position will be updated, moves will go up 
 * and the number of collectibles will go down by one. */
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
	return (write_moves(game), 1);
}

/* This function is in charge of moving the player up and down in the map.
 * */
int	move_up_down(t_game *game, char **map, int keycode)
{
	int	r;
	int	c;

	r = game->map.player_pos.row;
	c = game->map.player_pos.col;
	if (keycode == DOWN || keycode == S)
	{
		r++;
		if (map[r][c] == WALL || !can_move(game, map, r, c))
			return (0);
		map[r - 1][c] = OPEN_SPACE;
		update_map(game, r - 1, c, keycode);
	}
	else if (keycode == UP || keycode == W)
	{
		r--;
		if (map[r][c] == WALL || !can_move(game, map, r, c))
			return (0);
		map[r + 1][c] = OPEN_SPACE;
		update_map(game, r + 1, c, keycode);
	}
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
		if (map[r][c] == WALL || !can_move(game, map, r, c))
			return (0);
		map[r][c + 1] = OPEN_SPACE;
		update_map(game, r, c + 1, keycode);
	}
	else if (keycode == RIGHT || keycode == D)
	{
		c++;
		if (map[r][c] == WALL || !can_move(game, map, r, c))
			return (0);
		map[r][c - 1] = OPEN_SPACE;
		update_map(game, r, c - 1, keycode);
	}
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
	return (0);
}
