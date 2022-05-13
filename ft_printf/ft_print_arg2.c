/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:38 by eedy              #+#    #+#             */
/*   Updated: 2022/05/13 17:13:06 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_check_unsigned(va_list ptr, t_bolo *bolo)
{
	int	nbr;
	int	count

	nbr = va_arg(ptr, unsigned int);
	if (nbr == 0)
		count ++;
	count = ft_putnbr((unsigned int)nbr, count);
	return (count);
}

int	ft_checknbr(va_list ptr, t_bolo *bolo)
{
	int	nbr;
	int	count;

	nbr = va_arg(ptr, int);
	if (bolo -> space = 1)
	{
		write(1, " ", 1);
		count ++
	}
	if (bolo -> plus = 1)
	{
		if (nbr >= 0)
		{
			write(1, "+", 1);
			count ++;
		}
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		count ++;
	}
	count = ft_putnbr((unsigned int)nbr, count);
	return (count);
}

int	ft_putnbr(unsigned int nbr, int count)
{
	if (nbr)
		ft_putnbr(nbr / 10, count ++);
	nbr %= 10;
	write(1, &nbr, 1);
	return (count);
}

int	long_convert_ptr(va_list ptr)
{
	void				*pt;
	unsigned long long	nbr;
	int					count;

	i = 0;
	count = 0;
	pt = va_arg(ptr, void *);
	if (!pt)
	{
		write(1, "NULL", 4);
		count = 4;
	}
	else
	{
		nbr = (unsigned long long)pt;
		count = ft_print_hexa_lowercase(nbr, count);
	}
	return (count);
}
