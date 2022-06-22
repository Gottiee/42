/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:25:04 by eedy              #+#    #+#             */
/*   Updated: 2022/06/22 19:18:02 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_algo(t_count *count, t_rec *rec, t_lists *first)
{
	if (rec->argc == 3)
	{
		ft_printf("sa\n");
		return ;
	}
	else if (rec->stack_a[0] > rec->stack_a[1])
	{
		if (rec->stack_a[0] < rec->stack_a[2] && rec->stack_a[1] < rec->stack_a[2])
			call_instructions(SA, rec, count, first);
		else if (rec->stack_a[0] > rec->stack_a[2] && rec->stack_a[1] < rec->stack_a[2])
			call_instructions(RA, rec, count, first);
		else
		{
			call_instructions(SA, rec, count, first);
			call_instructions(RRA, rec, count, first);
		}
	}
	else
		small_algo2(count, rec, first);
}

void	small_algo2(t_count *count, t_rec *rec, t_lists *first)
{
	if (rec->stack_a[0] > rec->stack_a[2])
		call_instructions(RRA, rec, count, first);
	else
	{
		call_instructions(SA, rec, count, first);
		call_instructions(RA, rec, count, first);
	}
}

void	five_nbr_algo(t_count *count, t_rec *rec, t_lists *first)
{
	int	min;
	int	i;

	i = 0;
	if (rec->argc == 6)
		call_instructions(PB, rec, count, first);
	call_instructions(PB, rec, count, first);
	small_algo(count, rec, first);
	min = rec->stack_a[0];
	while (i < 3 && rec->stack_a[0] > rec->stack_b[0])
	{
		call_instructions(RA, rec, count, first);
		i ++;
	}
	call_instructions(PA, rec, count, first);
	if (rec->argc == 5)
		return ;
	while (i < 3 && rec->stack_a[0] > rec->stack_b[0])
	{
		call_instructions(RA, rec, count, first);
		i ++;
	}
	call_instructions(PA, rec, count, first);
	while (rec->stack_a[0] != min)
		call_instructions(RA, rec, count, first);
}
