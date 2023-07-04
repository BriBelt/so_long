/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:04:49 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/04 16:16:19 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_checker(t_game *game)
{
	char	*name;

	name = game->map.mapname;
	game->map.mapfd = open(name, O_RDONLY);
	if (game->map.mapfd <= 0 ||!map_format(name))
		return (0);
	game->map.rows = get_rows(game);
	get_map_cols(game);
	game->map.collectibles = 0;
	game->map.exit = 0;
	game->map.player = 0;
	if (game->map.rows == 0 || game->map.cols == 0)
		return (0);
	if (!check_map(game->map.map, game) ||!check_walls(game))
		return (0);
	if (game->map.player != 1 || game->map.exit < 1)
		return (0);
	return (1);
}

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

/* Gets the number of rows that there is in the map's file counting
 * the times that it is possible to use the GNL function without
 * its result being NULL */
int	get_rows(t_game *game)
{
	char	*read;
	int		rowcount;

	game->map.mapfd = open(game->map.mapname, O_RDONLY);
	read = get_next_line(game->map.mapfd);
	rowcount = 0;
	while (read)
	{
		free(read);
		rowcount++;
		read = get_next_line(game->map.mapfd);
	}
	close(game->map.mapfd);
	return (rowcount);
}

/* Will get the number of columns in the map, counting the length of
 * the string returned by the GNL function. It also adds those strings
 * as rows inside de array of strings "game->map.map". Sets the value
 * of game->map.cols automatically and creates the game->map.map. 
 * Returns nothing. */
void	get_map_cols(t_game *game)
{
	int		i;

	game->map.mapfd = open(game->map.mapname, O_RDONLY);
	game->map.map = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!game->map.map)
		exit_error("Memory error");
	game->map.cols = 0;
	i = 0;
	while (i < game->map.rows)
	{
		game->map.map[i] = get_next_line(game->map.mapfd);
		i++;
	}
	game->map.cols = ft_strlen(game->map.map[0]) - 1;
	game->map.map[i] = NULL;
	close(game->map.mapfd);
}

/* Checks if the map is rectangle/square shaped, also reads the whole
 * map, checking for the accepted characters (0, 1, P, E, C). Returns 
 * 0 if it found a character that is not accepted. */
int	check_map(char **map, t_game *game)
{
	int	i;
	int	j;
	int	collen;

	i = 0;
	collen = ft_strlen(map[i]);
	while (map[i])
	{
		if (collen != (int)ft_strlen(map[i]))
			return (0);
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (!accepted_chars(map[i][j], game))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Modifies the value of the numbt_game *gameer of collectibles, 
 * players and exits in the map, returns the corresponding number
 * if the passed character is a valid character for a map */
int	accepted_chars(char c, t_game *game)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (2);
	if (c == 'C')
	{
		game->map.collectibles++;
		return (3);
	}
	if (c == 'P')
	{
		game->map.player++;
		return (4);
	}
	if (c == 'E')
	{
		game->map.exit++;
		return (5);
	}
	return (0);
}

int	check_walls(t_game *game)
{
	int		row;
	int		col;
	int 	times;

	row = 0;
	times = 0;
	while (times++ <= 2)
	{
		col = 0;
		while (++col < game->map.cols - 1)
		{
			if (accepted_chars(game->map.map[row][col], game) != 1)
				return (0);
		}
		row = game->map.rows - 1;
	}
	col = 0;
	while (times++ <= 4)
	{
		row = 0;
		while (++row < game->map.rows)
		{
			if (accepted_chars(game->map.map[row][col], game) != 1)
				return (0);
		}
		col = game->map.cols - 1;
	}
	return (1);
}
