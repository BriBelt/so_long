/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:03:26 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/04 15:41:26 by bbeltran         ###   ########.fr       */
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
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit_error("Memory error");
	game->map.mapname = argv[1];
	if (ft_map_checker(game))
	{
		printf("Map created successfully\n");
		printf("rows: %i, cols: %i\n", game->map.rows, game->map.cols);
		printf("player: %i, collectibles: %i, exit: %i\n", game->map.player, game->map.collectibles, game->map.exit);
	}
	else
		exit_error("Non-valid map");
}
