/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:23:57 by eedy              #+#    #+#             */
/*   Updated: 2022/06/16 15:42:05 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	verif_tab(int *stack_a, t_count *count, int *stack_b)
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
