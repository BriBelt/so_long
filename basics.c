/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:47:55 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/08 18:40:50 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_connection(t_map **map, t_game *game)
{
	game->conn = mlx_init();
	game->win = mlx_new_window(game->conn, (*map)->cols * IMG_SIZE, (*map)->rows * IMG_SIZE, "so_long");
	create_images(game);
	mlx_loop(game->conn);
}
/*int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/
/*int	main(void)
{
	void	*conn;
	void	*win;
	t_data	img;
	
	conn = mlx_init();
	win = mlx_new_window(conn, 1920, 1080, "so_long");
	img.img = mlx_new_image(conn, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.lilen, &img.endian);
	mlx_put_image_to_window(conn, win, img.img, 0, 0);
	mlx_loop(conn);
	return (0);
}*/
