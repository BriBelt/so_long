/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:47:26 by bbeltran          #+#    #+#             */
/*   Updated: 2023/04/17 12:08:39 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, int *printed)
{
	write(fd, &c, 1);
	(*printed)++;
}

void	ft_putstr_fd(char *s, int fd, int *printed)
{
	int	index;

	index = 0;
	while (s && s[index] != '\0')
	{
		ft_putchar_fd(s[index], fd, printed);
		index++;
	}
}

void	ft_putun_nbr_fd(long n, int fd, int *printed)
{
	if (n >= 0)
		ft_putnbr_fd(n, fd, printed);
}

void	ft_putnbr_fd(long n, int fd, int *printed)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd, printed);
		ft_putnbr_fd(n * -1, fd, printed);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd, printed);
		ft_putchar_fd(n % 10 + '0', fd, printed);
	}
	else
		ft_putchar_fd(n + '0', fd, printed);
}

void	ft_putnbr_hex_fd(unsigned long n, int fd, char c, int *printed)
{
	unsigned long	remainder;

	remainder = 0;
	if (n != 0)
	{
		remainder = n % 16;
		ft_putnbr_hex_fd(n / 16, fd, c, printed);
	}
	if (remainder > 9)
	{
		if (c == 'X')
			ft_putchar_fd((remainder - 10) + 'A', fd, printed);
		else if (c == 'x')
			ft_putchar_fd((remainder - 10) + 'a', fd, printed);
	}
	else if (remainder <= 9 && n > 0)
		ft_putnbr_fd(remainder, fd, printed);
}
