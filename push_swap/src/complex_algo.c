/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:22:32 by eedy              #+#    #+#             */
/*   Updated: 2022/06/27 17:51:20 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	one_undred_and_less(int	size_chunck, t_count *count, t_rec *rec, t_lists *first)
{
	int	*cp_stack;
	int	pushed;
	
	if (verif_tab(rec->stack_a, count) || size_chunck == 2)
	{
		if (rec->stack_a[0] > rec->stack_a[1])
			call_instructions(SA, rec, count, first);
		return ;
	}
	cp_stack = sort_chunck(rec->stack_a, size_chunck);
	rec->mid_value = cp_stack[count->count_a / 2];
	pushed = push_chunck(size_chunck, rec, first, count);
	size_chunck -= pushed;
	printf("sizechunked = %d", size_chunck);
	one_undred_and_less(size_chunck, count, rec, first);
	if (pushed == 1)
		call_instructions(PA, rec, count, first);
	else if (pushed == 2)
	{
		if (rec->stack_b[0] > rec->stack_b[1])
			call_instructions(SB, rec, count, first);
		call_instructions(PA, rec, count, first);
		call_instructions(PA, rec, count, first);
	}
	else
	{
		size_chunck = manage_chunck(pushed, count, rec, first);
		printf("sizechunked = %d", size_chunck);
		one_undred_and_less(size_chunck, count, rec, first);
	}
	free(cp_stack);
}

int	manage_chunck(int pushed, t_count *count, t_rec *rec, t_lists *first)
{
	int	*cp_chunck;	
	int	*sort_ck;
	int	i;

	cp_chunck = malloc(sizeof(int) * (pushed) + 1);
	copy_chunck(cp_chunck, rec->stack_a, pushed);
	i = 0;
	if (verif_sort_chunck(cp_chunck, pushed))
	{
		while (i < pushed)
		{
			call_instructions(PA, rec, count, first);
			i ++;
		}
	}
	else 
	{
		sort_ck = sort_chunck(cp_chunck, pushed);
		rec->mid_value = sort_ck[pushed / 2];
		free(sort_ck);
		i = push_chunck_a(pushed, rec, first, count);
	}
	free(cp_chunck);
	return (i);
}

int	push_chunck(int size_chunck, t_rec *rec, t_lists *first, t_count *count)
{
	int	i;

	i = 0;
	while (i < size_chunck / 2)
	{
		if (rec->stack_a[0] < rec->mid_value)
		{
			call_instructions(PB, rec, count, first);
			i ++;
		}
		else if (rec->stack_a[count->count_a - 1] < rec->mid_value)
		{
			call_instructions(RRA, rec, count, first);
			call_instructions(PB, rec, count, first);
			i ++;
		}
		else
			call_instructions(RA, rec, count, first);
	}
	return (i);
}
