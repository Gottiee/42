/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:38 by eedy              #+#    #+#             */
/*   Updated: 2022/05/26 11:24:25 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	thanks_norminette(int *nbr, int count)
{
	count += write(1, "-", 1);
	if (*nbr == -2147483648)
	{
		count += write(1, "2147483648", 10);
		return (count);
	}
	(*nbr) *= -1;
	return (count);
}

int	ft_check_unsigned(va_list ptr)
{
	int	nbr;
	int	count;

	count = 0;
	nbr = va_arg(ptr, unsigned int);
	count = ft_putnbr((unsigned int)nbr, &count);
	return (count);
}

int	ft_checknbr(va_list ptr, t_bolo *bolo)
{
	int	nbr;
	int	count;

	count = 0;
	nbr = va_arg(ptr, int);
	if (bolo -> space == 1 && nbr >= 0)
	{
		write(1, " ", 1);
		count ++;
	}
	if (bolo -> plus == 1 && nbr >= 0)
	{
		if (nbr >= 0)
		{
			write(1, "+", 1);
			count ++;
		}
	}
	if (nbr < 0)
		count += thanks_norminette(&nbr, count);
	if (nbr != -2147483648)
		count = ft_putnbr((unsigned int)nbr, &count);
	return (count);
}

int	ft_putnbr(unsigned int nbr, int *count)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10, count);
	nbr %= 10;
	nbr += '0';
	(*count)++;
	write(1, &nbr, 1);
	return (*count);
}

int	long_convert_ptr(va_list ptr)
{
	void				*pt;
	unsigned long long	nbr;
	int					count;

	count = 0;
	pt = va_arg(ptr, void *);
	if (!pt)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		nbr = (unsigned long long)pt;
		count = ft_print_hexa_lowercase(nbr, &count);
	}
	return (count);
}
