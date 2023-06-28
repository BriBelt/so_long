/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:54:10 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/28 16:52:38 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/*char	**get_map(int fd)
{
	int	i;
	char	**arr;

	arr = NULL;
	i = 0;
	if (fd < 0)
		exit_error("Non-valid map");
	while (get_next_line(fd))
	{
		arr[i] = get_next_line(fd);
		i++;
	}
	return (arr);
}*/

void	exit_error(char *err)
{
	perror(err);
	exit(1);
}
