/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:03:26 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/13 10:27:24 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long_exec(argv);
	else
		exit_error("Please enter a valid mapfile.");
	return (0);
}

void	so_long_exec(char **argv)
{
	t_map	**map;
	t_game	*game;

	if (!argv[1] || argv[1][0] == '\0')
		exit_error("Empty mapfile.");
	if (!map_format(argv[1], ".ber"))
		exit_error("Non-valid mapfile format.");
	map = create_map(argv[1]);
	error_checker(map);
	game = malloc(sizeof(t_game));
	if (!game)
		exit_error("Memory error.");
	game->map = init_game_map(map);
	game->moves = 0;
	create_connection(game);
}

t_cmap	init_game_map(t_map **map)
{
	t_cmap	newmap;

	newmap.fmap = get_charmap(map);
	newmap.collectibles = (*map)->collectibles;
	newmap.player_pos = (*map)->player_pos;
	newmap.exit_pos = (*map)->exit_pos;
	newmap.cols = (*map)->cols;
	newmap.rows = (*map)->rows;
	free_map(map);
	return (newmap);
}

void	error_checker(t_map **map)
{
	char	**check;

	if (!map)
		exit_error("Could not create map.");
	if (!check_chars(map))
		exit_error("Map must have accepted characters and be rectangular.");
	if (!check_walls(map))
		exit_error("Map must be rectangular and surrounded by walls.");
	if ((*map)->player != 1)
		exit_error("There must be at least one player.");
	if ((*map)->exit != 1)
		exit_error("There must be at least one exit.");
	if ((*map)->collectibles < 1)
		exit_error("There must be at least one collectible.");
	check = get_charmap(map);
	if (!can_reach(check, map))
		exit_error("All targets must be reachable.");
	ft_freearray(check);
	check_images("img/floor.xpm");
	check_images("img/wall.xpm");
	check_images("img/collectible.xpm");
	check_images("img/exit.xpm");
	check_images("img/s_player.xpm");
}

void	check_images(char *imagepath)
{
	int	fd;
	fd = open(imagepath, O_RDONLY);
	if (fd <= 0)
		exit_error("Could not find the image.");
}
