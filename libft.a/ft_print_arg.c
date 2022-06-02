/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:21 by eedy              #+#    #+#             */
/*   Updated: 2022/06/02 15:19:26 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(va_list ptr)
{
	int	c;

	c = va_arg(ptr, int);
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(va_list ptr)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	str = va_arg(ptr, char *);
	if (!str)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (str[i])
	{
		write(1, str + i, 1);
		i ++;
		count ++;
	}
	return (count);
}

int	long_convert(va_list ptr, int check, t_bolo *bolo)
{
	unsigned long long	nbr;
	int					count;

	count = 0;
	nbr = va_arg(ptr, unsigned int);
	if (check == 6)
	{
		if (bolo -> hastag == 1 && nbr > 0)
		{
			write(1, "0x", 2);
			count += 2;
		}
		count = ft_print_hexa_lowercase(nbr, &count);
	}
	else
	{
		if (bolo -> hastag == 1 && nbr > 0)
		{
			write(1, "0X", 2);
			count += 2;
		}
		count = ft_print_hexa_uppercase(nbr, &count);
	}
	return (count);
}

int	ft_print_hexa_lowercase(unsigned long long nbr, int *count)
{
	const char	*str = "0123456789abcdef";

	if (nbr > 15)
		ft_print_hexa_lowercase(nbr / 16, count);
	nbr %= 16;
	write(1, str + nbr, 1);
	(*count)++;
	return (*count);
}

int	ft_print_hexa_uppercase(unsigned long long nbr, int *count)
{
	const char	*str = "0123456789ABCDEF";

	if (nbr > 15)
		ft_print_hexa_uppercase(nbr / 16, count);
	nbr %= 16;
	write(1, str + nbr, 1);
	(*count)++;
	return (*count);
}
