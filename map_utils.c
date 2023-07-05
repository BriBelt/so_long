/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:01:51 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/05 19:18:42 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Will check weather the file name is the correct format ".ber"
 * if not, returns a 0 */
int	map_format(char *name)
{
	int		len;
	int		i;
	char	*format;

	len = ft_strlen(name) - 4;
	i = 0;
	if (len <= 0)
		return (0);
	format = ".ber";
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
	int		i;
	
	i = 0;
	ptr = *map;
	while (i < rownum)
	{
		ptr = ptr->next;
		i++;
	}
	return (ptr);
}

/* Flood fill algorithm that will check from the player's position
 * if both the collectibles and the exit are reachable for the player */
void	ft_flood_fill(t_map *row, int rownum, int col)
{
	t_map	*drow;

	drow = get_row(row, rownum);

	ft_flood_fill(row, rownum - 1, col);
	ft_flood_fill(row, rownum + 1, col);
	ft_flood_fill(row, rownum, col - 1);
	ft_flood_fill(row, rownum, col + 1);
}
