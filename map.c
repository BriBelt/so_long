/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:04:49 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/05 18:07:38 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* --- LIST CREATION --- */

/* Creates the map using linked lists, also modifies the
 * number of rows that the map has. Uses map_format
 * function to check if the file format is correct.
 * Also checks if the file can be opened, if anything
 * goes wrong, returns a 0. */
t_map	**create_map(char *mapfile)
{
	t_map	**map;
	char	*row;
	int		fd;

	if (!map_format(mapfile))
		return (0);
	fd = open(mapfile, O_RDONLY);
	if (fd <= 0)
		return (0);
	map = malloc(sizeof(t_map *));
	if (!map)
		return (0);
	*map = NULL;
	row = get_next_line(fd);
	while (row != NULL)
	{
		insert_row(map, row);
		(*map)->rows++;
		row = get_next_line(fd);
	}
	free(row);
	return (map);
}

/* --- LIST CHECKING --- */
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

/* Checks if the map is rectangle/square shaped, also reads the whole
 * map, checking for the accepted characters (0, 1, P, E, C). Returns 
 * 0 if it found a character that is not accepted. */
int	check_chars(t_map **map)
{
	int		i;
	size_t	collen;
	t_map	*ptr;

	i = 0;
	ptr = *map;
	collen = ft_strlen(ptr->data);
	while (ptr)
	{
		if (collen != ft_strlen(ptr->data))
			return (0);
		i = 0;
		while (ptr->data[i] && ptr->data[i]!= '\n')
		{
			if (!accepted_chars(ptr->data[i], map)) 
				return (0);
			i++;
		}
		ptr = ptr->next;
	}
	(*map)->cols = collen - 1;
	return (1);
}

int	check_walls(t_map **map)
{
	t_map	*ptr;
	int		times;
	int		col;

	times = 0;
	col = 0;
	ptr = *map;
	while (times++ <= 2)
	{
		col = 0;
		while (++col < (*map)->cols)
		{
			if (accepted_chars(ptr->data[col], map) != 1)
				return (0);
		}
		ptr = lstlast(ptr);
	}
	col = 0;
	times = 0;
	while (times++ <= 2)
	{
		ptr = *map;
		while (ptr)
		{
			if (accepted_chars(ptr->data[col], map) != 1)
				return (0);
			ptr = ptr->next;
		}
		col = (*map)->cols - 1;
	}
	return (1);
}

void	ft_flood_fill(t_map **map, int row, int col)
{
	
}
