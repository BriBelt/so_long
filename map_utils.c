/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:01:51 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/08 12:24:32 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Will check weather the file name is the correct format ".ber"
 * if not, returns a 0 */
int	map_format(char *name, char *format)
{
	int		len;
	int		flen;
	int		i;

	flen = ft_strlen(format);
	len = ft_strlen(name) - flen;
	i = 0;
	if (len <= 0)
		return (0);
	while (name[len])
	{
		if (name[len] == format[i])
		{
			len++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

/* Modifies the value of the of collectibles, 
 * players and exits in the map, returns the corresponding number
 * if the passed character is a valid character for a map */
int	accepted_chars(char c, t_map **map)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (2);
	if (c == 'C')
	{
		(*map)->collectibles++;
		return (3);
	}
	if (c == 'P')
	{
		(*map)->player++;
		return (4);
	}
	if (c == 'E')
	{
		(*map)->exit++;
		return (5);
	}
	return (0);
}

t_map	*get_row(t_map **map, int rownum)
{
	t_map	*ptr;
	
	ptr = *map;
	while (ptr->index < rownum)
		ptr = ptr->next;
	return (ptr);
}

char	**get_charmap(t_map **map)
{
	char	**newmap;
	t_map	*ptr;
	int		i;

	i = 0;
	newmap = ft_calloc((*map)->rows + 1, sizeof(char *));
	if (!newmap)
		return (0);
	ptr = *map;
	while (ptr)
	{
		newmap[i] = ft_dup(ptr->data);
		ptr = ptr->next;
		i++;
	}
	return (newmap);
}

/* Flood fill algorithm that will check from the player's position
 * if both the collectibles and the exit are reachable for the player */
void	flood_fill(char **map, t_pos size, int row, int col, int *total)
{
	if ((row >= size.row || row < 0) ||
			(col >= size.col || col < 0))
		return ;
	if (map[row][col] == '1' ||map[row][col] == 'X')
		return ;
	if (map[row][col] == 'C')
		(*total)++;
	if (map[row][col] == 'E')
		(*total)++;
	map[row][col] = 'X';
	flood_fill(map, size, row - 1, col, total);
	flood_fill(map, size, row + 1, col, total);
	flood_fill(map, size, row, col - 1, total);
	flood_fill(map, size, row, col + 1, total);
}

int	can_reach(char **map, t_map **omap)
{
	int		total;
	int		orgtotal;
	t_pos	size;
	int		pr;
	int		pc;

	total = 0;
	orgtotal = (*omap)->collectibles + (*omap)->exit;
	size.row = (*omap)->rows - 1;
	size.col = (*omap)->cols - 1;
	pr = (*omap)->player_pos.row;
	pc = (*omap)->player_pos.col;
	flood_fill(map, size, pr, pc, &total);
	if (total != orgtotal)
		return (0);
	return (1);
}
