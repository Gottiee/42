/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:58:09 by eedy              #+#    #+#             */
/*   Updated: 2022/07/11 18:20:18 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ty_nor(int size)
{
	if (size == -1)
	{
		ft_printf("malloc error manage_chunck\n");
		exit(0);
	}
}

int	manage2(int pushed, int *cp_chunck, t_rec *rec)
{
	int	*sort_ck;

	sort_ck = sort_chunck(cp_chunck, pushed);
	if (!sort_ck)
		return (-1);
	rec->mid_value = sort_ck[pushed / 2 - 1];
	free(sort_ck);
	return (0);
}

void	swap(int min, int i, int *cp_stack)
{
	int	tmp;

	tmp = cp_stack[min];
	cp_stack[min] = cp_stack[i];
	cp_stack[i] = tmp;
}
