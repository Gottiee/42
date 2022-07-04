/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:22:32 by eedy              #+#    #+#             */
/*   Updated: 2022/07/04 14:21:12 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	one(int size_chunck, t_count *count, t_rec *rec, t_lists *first)
{
	int	pushed;

	if (ver(size_chunck, rec, first, count))
		return ;
	pushed = ty_n(&size_chunck, rec, first, count);
	while (1 && pushed != 0)
	{
		if (pushed == 1)
		{
			call_instructions(PA, rec, count, first);
			break ;
		}
		else if (pushed == 2)
		{
			egual2(rec, first, count);
			break ;
		}
		else
		{
			size_chunck = manage_chunck(pushed, count, rec, first);
			pushed -= size_chunck;
			one(size_chunck, count, rec, first);
		}
	}
}

int	manage_chunck(int pushed, t_count *count, t_rec *rec, t_lists *first)
{
	int	*cp_chunck;	
	int	*sort_ck;
	int	i;

	cp_chunck = malloc(sizeof(int) * (pushed) + 1);
	copy_chunck(cp_chunck, rec->stack_b, pushed);
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
		rec->mid_value = sort_ck[pushed / 2 - 1];
		free(sort_ck);
		i = push_a(pushed, rec, first, count);
	}
	free(cp_chunck);
	return (i);
}

int	push(int size_chunck, t_rec *rec, t_lists *first, t_count *count)
{
	int	i;
	int	count_ra;

	i = 0;
	count_ra = 0;
	while (i < size_chunck / 2)
	{
		if ((rec->stack_a[0] < rec->mid_value)
			|| (rec->stack_a[count->count_a - 1] < rec->mid_value))
			push2(&i, rec, first, count);
		else
		{
			call_instructions(RA, rec, count, first);
			count_ra ++;
		}
	}
	if (rec->bolo == 1)
	{
		while (count_ra)
		{
			call_instructions(RRA, rec, count, first);
			count_ra --;
		}
	}
	return (i);
}

void	push2(int *i, t_rec *rec, t_lists *first, t_count *count)
{
	if (rec->stack_a[0] < rec->mid_value)
	{
		call_instructions(PB, rec, count, first);
		(*i)++;
	}
	else if (rec->stack_a[count->count_a - 1] < rec->mid_value)
	{
		call_instructions(RRA, rec, count, first);
		call_instructions(PB, rec, count, first);
		(*i)++;
	}
}
