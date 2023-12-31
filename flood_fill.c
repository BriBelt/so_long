/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:16:02 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/24 12:41:07 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Flood fill algorithm that will check from the player's position
 * if both the collectibles and the exit are reachable for the player */
void	flood_fill(char **map, t_pos size, int row, int col)
{
	if ((row >= size.row || row < 0) || (col >= size.col || col < 0))
		return ;
	if (map[row][col] == '1' || map[row][col] == 'X')
		return ;
	map[row][col] = 'X';
	flood_fill(map, size, row - 1, col);
	flood_fill(map, size, row + 1, col);
	flood_fill(map, size, row, col - 1);
	flood_fill(map, size, row, col + 1);
}

/* Will call both the flood_fill and the count_totalfound functions,
 * if the result of the last function is not 0, it means that there's
 * some non-reacheable characters, therefore, the map is non-valid. */
int	can_reach(char **map, t_map **omap)
{
	t_pos	size;
	int		pr;
	int		pc;

	size.row = (*omap)->rows - 1;
	size.col = (*omap)->cols - 1;
	pr = (*omap)->player_pos.row;
	pc = (*omap)->player_pos.col;
	flood_fill(map, size, pr, pc);
	if (count_totalfound(map) == 0)
		return (1);
	return (0);
}

/* This function will check all the characters inside the 
 * flood-fill-modified map, it will return the number of 
 * collectible and exit characters found inside the map. */
int	count_totalfound(char **map)
{
	int	r;
	int	c;
	int	found;

	r = 0;
	found = 0;
	while (map[r])
	{
		c = 0;
		while (map[r][c])
		{
			if (map[r][c] == COLLECTIBLE || map[r][c] == EXIT)
				found++;
			c++;
		}
		r++;
	}
	return (found);
}
