/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:23:57 by eedy              #+#    #+#             */
/*   Updated: 2022/06/17 18:03:12 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	verif_tab(int *stack_a, t_count *count)
{
	int max_nbr;
	int	i;

	if (count->count_b != 0)
		return (0);
	max_nbr = stack_a[0];
	i = 1;	
	while (i < count->count_a)
	{
		if (stack_a[i] < max_nbr)
			return (0);
		max_nbr = stack_a[i];
		i ++;
	}
	return (1);
}

void	copy_a(int *cp_a, int *stack_a, t_count *count)
{
	int	i;

	i = 0;
	while (i < count->count_a)
	{
		cp_a[i] = stack_a[i];
		i ++;
	}
}
