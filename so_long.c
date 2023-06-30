/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:03:26 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/30 15:27:45 by bbeltran         ###   ########.fr       */
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
	game->map.mapname = argv[1];
	map_format(game);
	game->map.mapfd = open(game->map.mapname, O_RDONLY);
	if (game->map.mapfd <= 0)
		exit_error("Non-valid map");
	get_rows(game);
	get_cols(game);
	if (check_map(game->map.map))
		printf("Valid map\n");
//	printf("%i\n", game->map.rows);
//	int i = 0;
//	while (game->map.map[i])
//	{
//		printf("%s", game->map.map[i]);
//		i++;
//	}
}
