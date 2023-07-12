/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:54:10 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/12 19:24:40 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *err)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char	*ft_dup(const char *s1)
{
	size_t	slen;
	char	*str;

	slen = ft_strlen(s1);
	str = (char *) malloc(slen * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, slen);
	return (str);
}

void	cc_images(void *conn, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(conn, path, &width, &height);
	if (*image == NULL)
		exit_error("Could not find the image");
}
