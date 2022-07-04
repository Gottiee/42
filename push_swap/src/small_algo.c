/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:25:04 by eedy              #+#    #+#             */
/*   Updated: 2022/07/04 16:41:04 by eedy             ###   ########.fr       */
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
		if (rec->stack_a[0] < rec->stack_a[2]
			&& rec->stack_a[1] < rec->stack_a[2])
			call_instructions(SA, rec, count, first);
		else if (rec->stack_a[0] > rec->stack_a[2]
			&& rec->stack_a[1] < rec->stack_a[2])
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
