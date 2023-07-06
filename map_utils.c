/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:01:51 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/06 19:16:38 by bbeltran         ###   ########.fr       */
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

/* Flood fill algorithm that will check from the player's position
 * if both the collectibles and the exit are reachable for the player */
/*void	flood_fill(t_map **mapcopy, int rownum, int col)
{
	t_map	*row;

	row = get_row(mapcopy, rownum);
//	printf("ffrow: %s, rownum: %i, colnum: %i, maxrow: %i, maxcol: %i\n",
//			row->data, rownum, col, (*mapcopy)->rows - 1, (*mapcopy)->cols - 1);
	if ((rownum > (*mapcopy)->rows - 1 || rownum < 0) ||
			(col > (*mapcopy)->cols - 1 || col < 0))
	{
//		printf("passes limits\n");
		return ;
	}
	if (row->data[col] == '1')
	{
//		printf("reached a wall\n");
		return ;
	}
	if (row->data[col] == 'C')
		(*mapcopy)->collectibles++;
	if (row->data[col] == 'E')
		(*mapcopy)->exit++;
	row->data[col] = 'X';
	flood_fill(mapcopy, rownum - 1, col);
	flood_fill(mapcopy, rownum + 1, col);
	flood_fill(mapcopy, rownum, col - 1);
	flood_fill(mapcopy, rownum, col + 1);
}*/

char	**get_charmap(t_map **map)
{
	char	**newmap;
	t_map	*ptr;
	int		i;
	
	i = 0;
	newmap = malloc(sizeof(char *) * (*map)->rows);
	if (!newmap)
		return (0);
	ptr = *map;
	while (ptr)
	{
		newmap[i] = ft_dup(ptr->data);
		i++;
		ptr = ptr->next;
	}
	return (newmap);
}

/*void	flood_fill(char **mapcopy, int rownum, int col)
{
	if ((rownum > (*mapcopy)->rows - 1 || rownum < 0) ||
			(col > (*mapcopy)->cols - 1 || col < 0))
	{
//		printf("passes limits\n");
		return ;
	}
	if (row[col] == '1')
	{
//		printf("reached a wall\n");
		return ;
	}
	if (row[col] == 'C')
		(*mapcopy)->collectibles++;
	if (row[col] == 'E')
		(*mapcopy)->exit++;
	row[col] = 'X';
	flood_fill(mapcopy, rownum - 1, col);
	flood_fill(mapcopy, rownum + 1, col);
	flood_fill(mapcopy, rownum, col - 1);
	flood_fill(mapcopy, rownum, col + 1);
}

int	can_reach(char *mapfile, t_map **map)
{
	t_map	**mapcopy;

	mapcopy = create_map(mapfile);
	if (!check_chars(mapcopy))
		return (0);
	(*mapcopy)->exit = 0;
	(*mapcopy)->collectibles = 0;
//	printf("player position row: %i, col: %i\n", (*mapcopy)->player_pos.row, (*mapcopy)->player_pos.col);
	flood_fill(mapcopy, (*mapcopy)->player_pos.row,
			(*mapcopy)->player_pos.col);
	if ((*map)->exit != (*mapcopy)->exit ||
			(*map)->collectibles != (*mapcopy)->collectibles)
		return (0);
	return (1);
}*/
