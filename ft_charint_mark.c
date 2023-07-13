/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charint_mark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:12:49 by bbeltran          #+#    #+#             */
/*   Updated: 2023/04/14 20:24:07 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_charint_mark(int c, int *i, int *printed, char ioc)
{
	if (ioc == 'c')
		ft_putchar_fd(c, 1, printed);
	else if (ioc == 'n')
		ft_putnbr_fd(c, 1, printed);
	else if (ioc == 'u')
		ft_putun_nbr_fd((unsigned int)c, 1, printed);
	(*i) += 2;
}
