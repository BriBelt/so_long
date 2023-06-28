/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:03:26 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/28 17:47:17 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long_exec(argv);
	return (0);
}

void	so_long_exec(char **argv)
{
	t_game	game;
//	char	*wholemap;

	game.mapname = argv[1];
	map_format(game);
	game.mapfd = open(game.mapname, O_RDONLY);
	if (game.mapfd <= 0)
		exit_error("Non-valid map");
	game.rows = n_rows(game);
	game.cols = n_cols(game);
	game.map = get_wholemap(game);	
	printf("rows: %i cols: %i\n", game.rows, game.cols);
	int	i = 0;
	while (game.map[i])
	{
		printf("%s", game.map[i]);
		i++;
	}
}
