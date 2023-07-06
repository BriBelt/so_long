/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:01:51 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/06 17:21:56 by bbeltran         ###   ########.fr       */
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
	
	ptr = *map;
	while (ptr->index < rownum)
		ptr = ptr->next;
	return (ptr);
}

void	flood_fill(t_map **map, int rownum, int col)
{
	t_map	*row;

	row = get_row(map, rownum);
	if ((rownum > (*map)->rows - 1 || rownum < 0) ||
			(col > (*map)->cols - 1 || col < 0))
		return ;

}
/*int	reachable(char *mapfile, t_map **map)
{
	t_map	**copy;

	copy = create_map(mapfile);

}*/
/* Flood fill algorithm that will check from the player's position
 * if both the collectibles and the exit are reachable for the player */
/*void	flood_fill(t_map **map, int rownum, int col)
{
	t_map	*row;
	int		c;
	int		e;

	c = 0;
	e = 0;
	row = get_row(map, rownum);
	if ((rownum > (*map)->rows - 1 || rownum < 0) ||
			(col > (*map)->cols - 1 || col < 0))
		return ;
	if (row[col] == 'X' || accepted_chars(row[col]) == 1)
		return ;
	if (row[col] == 'C')
		c++;
	if (row[col] == 'E')
		e++;
	if (e != (*map)->exit || c != (*map)->collectibles)
}*/
