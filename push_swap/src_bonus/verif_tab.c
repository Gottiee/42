/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:23:57 by eedy              #+#    #+#             */
/*   Updated: 2022/06/16 15:28:31 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	verif_tab(int *stack_a, t_count *count, int *stack_b)
{
	int max_nbr;
	int	i;

	if (count->count_b != 0)
		end_center(TAB_PRB, stack_a, stack_b);
	max_nbr = stack_a[0];
	i = 1;	
	while (i < count->count_a)
	{
		if (stack_a[i] < max_nbr)
			end_center(TAB_PRB, stack_a, stack_b);
		max_nbr = stack_a[i];
		i ++;
	}
	end_center(WIN, stack_a, stack_b);
}
