/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:04:49 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/30 16:00:57 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_format(t_game *game)
{
	int		len;
	int		i;
	char	*format;

	len = ft_strlen(game->map.mapname) - 4;
	i = 0;
	if (len <= 0)
		exit_error("Non-valid map\n");
	format = ".ber";
	while (game->map.mapname[len])
	{
		if (game->map.mapname[len] == format[i])
		{
			len++;
			i++;
		}
		else
			exit_error("Non-valid map\n");
	}
}

void	get_rows(t_game *game)
{
	char	*read;
	
	game->map.mapfd = open(game->map.mapname, O_RDONLY);
	read = get_next_line(game->map.mapfd);
	game->map.rows = 0;
	while (read)
	{
		free(read);
		game->map.rows++;
		read = get_next_line(game->map.mapfd);
	}
	close(game->map.mapfd);
	if (game->map.rows == 0)
		exit_error("Non-valid map\n");
}

void	get_cols(t_game *game)
{
	int		i;

	game->map.mapfd = open(game->map.mapname, O_RDONLY);
	game->map.map = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!game->map.map)
		exit_error("Memory error");
	i = 0;
	while (i < game->map.rows)
	{
		game->map.map[i] = get_next_line(game->map.mapfd);
		i++;
	}
	game->map.map[i] = NULL;
	close(game->map.mapfd);
}

/*int	n_rows(t_game game)
{
	char	*read;
	int		row;

	row = 0;
	game.mapfd = open(game.mapname, O_RDONLY);
	while (1)
	{
		read = get_next_line(game.mapfd);
		if (read == NULL)
			break ;
		free(read);
		row++;
	}
	close(game.mapfd);
	return (row);
}

int	n_cols(t_game game)
{
	char	*read;
	int		col;

	game.mapfd = open(game.mapname, O_RDONLY);
	read = get_next_line(game.mapfd);
	col = ft_strlen(read);
	free(read);
	close(game.mapfd);
	return (col);
}*/

int	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (!accepted_chars(map[i][j]))
				exit_error("Non-valid map\n");
			j++;
		}
		i++;
	}
	return (1);
}

int	check_borders(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
}

int	accepted_chars(char c)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (2);
	if (c == 'C')
		return (3);
	if (c == 'P')
		return (4);
	if (c == 'E')
		return (5);
	return (0);
}
