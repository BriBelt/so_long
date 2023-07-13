/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:00:19 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/12 20:12:17 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hex_mark(unsigned int hexval, int *i, int *printed, char c)
{
	if (hexval == 0)
	{
		ft_putnbr_fd(0, 1, printed);
		(*i) += 2;
	}
	else
	{
		ft_putnbr_hex_fd(hexval, 1, c, printed);
		(*i) += 2;
	}
}

static void	ft_pointer_mark(unsigned long ptr, int *i, int *printed)
{
	if (!ptr)
		ft_putstr_fd("0x0", 1, printed);
	else
	{
		ft_putstr_fd("0x", 1, printed);
		ft_putnbr_hex_fd(ptr, 1, 'x', printed);
	}
	(*i) += 2;
}

static void	ft_str_mark(char *argstr, int *i, int *printed)
{
	if (!argstr)
		ft_putstr_fd("(null)", 1, printed);
	else
		ft_putstr_fd(argstr, 1, printed);
	(*i) += 2;
}

void	check_rest(const char *format, int *i, va_list *ap, int *printed)
{
	if (format[*i] == '%' && (format[(*i) + 1] == 'x'
			|| format[(*i) + 1] == 'X'))
		ft_hex_mark(va_arg(*ap, unsigned int), i, printed, format[(*i) + 1]);
	else if (format[*i] == '%' && format[*i + 1] == '%')
		ft_charint_mark(format[*i + 1], i, printed, 'c');
	else
		ft_putchar_fd(format[(*i)++], 1, printed);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	printed = 0;
	while (i < ft_strlen(format) && format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
			ft_charint_mark(va_arg(ap, int), &i, &printed, 'c');
		else if (format[i] == '%' && format[i + 1] == 's')
			ft_str_mark(va_arg(ap, char *), &i, &printed);
		else if (format[i] == '%' && format[i + 1] == 'p')
			ft_pointer_mark(va_arg(ap, unsigned long), &i, &printed);
		else if (format[i] == '%'
			&& (format[i + 1] == 'd' || format[i + 1] == 'i'))
			ft_charint_mark(va_arg(ap, int), &i, &printed, 'n');
		else if (format[i] == '%' && format[i + 1] == 'u')
			ft_charint_mark(va_arg(ap, unsigned int), &i, &printed, 'u');
		else
			check_rest(format, &i, &ap, &printed);
	}
	va_end(ap);
	return (printed);
}
