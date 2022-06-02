/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:21:32 by eedy              #+#    #+#             */
/*   Updated: 2022/05/27 14:35:19 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	distrib(int check, va_list ptr, t_bolo *bolo)
{
	int	count;

	if (check == 1)
		count = ft_putchar(ptr);
	if (check == 2)
		count = ft_putstr(ptr);
	if (check == 3)
		count = long_convert_ptr(ptr);
	if (check == 4)
		count = ft_checknbr(ptr, bolo);
	if (check == 5)
		count = ft_check_unsigned(ptr);
	if (check == 6 || check == 7)
		count = long_convert(ptr, check, bolo);
	if (check == 8)
	{
		write(1, "%", 1);
		count = 1;
	}
	return (count);
}

int	check_str(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (2);
	if (c == 'p')
		return (3);
	if (c == 'd' || c == 'i')
		return (4);
	if (c == 'u')
		return (5);
	if (c == 'x')
		return (6);
	if (c == 'X')
		return (7);
	if (c == '%')
		return (8);
	else
		return (0);
}

int	print_str(const char *str, int *i, va_list ptr, t_bolo *bolo)
{
	int	count;
	int	check;
	int	str_len;

	str_len = ft_strlen(str);
	count = 0;
	while (*i < str_len)
	{
		if (*i + 1 < str_len && str[*i] == '%')
		{
			(*i)++;
			check_flags(str, i, str_len, bolo);
			check = check_str(str[*i]);
			if (check == 0)
				return (-1);
			count += distrib(check, ptr, bolo);
			init_bolo(bolo);
			(*i)++;
		}
		if (*i < str_len && str[*i] != '%')
			ft_print_str_ext(&count, i, str);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	t_bolo	*bolo;	
	int		count;
	int		i;

	i = 0;
	va_start(ptr, str);
	bolo = malloc(sizeof(t_bolo));
	if (!bolo)
		return (0);
	init_bolo(bolo);
	count = print_str(str, &i, ptr, bolo);
	free(bolo);
	if (count < 0)
		return (-1);
	return (count);
}
