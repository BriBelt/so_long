/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:03:26 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/06 15:23:31 by bbeltran         ###   ########.fr       */
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
	t_map	**map;

	game = malloc(sizeof(t_game));
	if (!game)
		exit_error("Memory error");
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
	t_map *ptr;

	ptr = *map;
	while (ptr)
	{
		printf("total rows: %i, total cols %i\n node: %i-- %s\n", ptr->rows, ptr->cols, ptr->index, ptr->data);
		ptr = ptr->next;
	}
	free(game);
	free_map(map);
}
