/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_steps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:31:43 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/25 15:30:45 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_moves(t_game *game)
{
	if (BONUS == 1)
		bonus_place_steps(game);
	else if (BONUS == 0)
	{
		ft_putstr_fd("Steps: ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putstr_fd("\n", 1);
	}
}
