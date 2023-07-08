/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:03:26 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/08 18:00:14 by bbeltran         ###   ########.fr       */
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
	t_map	**map;
	char	**newmap;
	t_game	*game;

	map = create_map(argv[1]);
	if (!map)
		exit_error("Could not create map");
	if (!check_chars(map) || !check_walls(map) ||
			(*map)->player != 1 || (*map)->exit != 1)
	{
		printf("Map created, rows: %i, cols: %i, players: %i, collect: %i, exit: %i\n",
			(*map)->rows, (*map)->cols, (*map)->player, (*map)->collectibles, (*map)->exit); 
		exit_error("Non-valid map");
	}
	newmap = get_charmap(map);
	if (!can_reach(newmap, map))
		exit_error("Non-reachable target");
	game = malloc(sizeof(t_game));
	if (!game)
		exit_error("Memory error");
	create_connection(map, game);
	free_map(map);
}
