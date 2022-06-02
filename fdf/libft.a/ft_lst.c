/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:59:42 by eedy              #+#    #+#             */
/*   Updated: 2022/05/27 14:34:24 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_bolo(t_bolo *bolo)
{
	bolo -> hastag = 0;
	bolo -> space = 0;
	bolo -> plus = 0;
}

int	check_flags(const char *str, int *i, int str_len, t_bolo *bolo)
{
	while (*i < str_len && (str[*i] == ' ' || str[*i] == '+' || str[*i] == '#'))
	{
		if (str[*i] == ' ')
			bolo -> space += 1;
		if (str[*i] == '+')
			bolo -> plus += 1;
		if (str[*i] == '#')
			bolo -> hastag += 1;
		(*i)++;
	}
	if (bolo -> space > 1 && bolo -> plus > 1)
		bolo -> space = 0;
	return (0);
}
