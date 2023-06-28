/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:04:49 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/28 17:47:15 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_format(t_game game)
{
	int		len;
	int		i;
	char	*format;

	len = ft_strlen(game.mapname) - 4;
	i = 0;
	if (len <= 0)
		exit_error("Non-valid map\n");
	format = ".ber";
	while (game.mapname[len])
	{
		if (game.mapname[len] == format[i])
		{
			len++;
			i++;
		}
		else
			exit_error("Non-valid map\n");
	}
}

int	n_rows(t_game game)
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
}

char	**get_wholemap(t_game game)
{
	char	*read;
	char	**whole;
	int		i;

	whole = ft_calloc(game.rows + 1, sizeof(char *));
	if (!whole)
		return (NULL);
	i = 0;
	game.mapfd = open(game.mapname, O_RDONLY);
	while (i < game.rows)
	{
		read = get_next_line(game.mapfd);
		whole[i] = read;
		i++;
	}
	close(game.mapfd);
	return (whole);
}

/*char	*get_wholemap(t_game game)
{
	char	*tmprow;
	char	*wholemap;

	wholemap = NULL;
	tmprow = NULL;
	game.rows = 0;
	while (1)
	{
		tmprow = get_next_line(game.mapfd);
		if (tmprow == NULL)
			break ;
		wholemap = ft_strjoin(wholemap, tmprow);
		game.rows++;
		free(tmprow);
	}
	return (wholemap);
}*/

