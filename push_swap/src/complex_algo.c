/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:22:32 by eedy              #+#    #+#             */
/*   Updated: 2022/06/24 19:09:08 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	one_undred_and_less(t_count *count, t_rec *rec, t_lists *first)
{
	int	manage;

	find_lower(rec, count);
	check_push(rec, count);
	while (count->count_a)
	{
		manage = manage_move;
		if (manage == 1)
			manage_lower(rec, count, first);
		else if (manage == 2)
			manage_hold_then(rec, count, first);
		else if (manage == 3)
			manage_upper(rec, count, first);
		else
			manage_hold_before(rec, count, first);
		find_lower(rec, count);
		check_push(rec, count);
	}
	while (count->count_b)
		call_instructions(PA, rec, count, first);
}

void	manage_lower(t_rec *rec, t_count *count, t_lists *first)
{
	int	 i;

	i = 0;
	if (rec->nbr_move_lower <= rec->nbr_move_hold ) 
	{
		while (i++ < rec->nbr_move_lower)
			call_instructions(rec->move_lower, rec, count, first);
		i = 0;
	}
	if ((rec->nbr_move_lower <= rec->nbr_move_hold && rec->count == 0) || (count->count_a == 1 && rec->count == 0))
	{
		call_instructions(PB, rec, count, first);
		find_lower(rec, count);
	}
	else if ((rec->nbr_move_lower <= rec->nbr_move_hold && rec->count != 0) || (count->count_a == 1 && rec->count != 0))
		manage_lower2(i, rec, count, first);
}

void	manage_lower2(int i, t_rec *rec, t_count *count, t_lists *first)
{
	if (rec->count == 1)
	{
		call_instructions(RB, rec, count, first);
		call_instructions(PB, rec, count, first);
		call_instructions(RRB, rec, count, first);
		rec->count = 0;
	}
	else
	{
		while (i < rec->count)
		{
			call_instructions(RB, rec, count, first);
			i ++;
		}
		call_instructions(PB, rec, count, first);
		while (i > 0) 
		{
			call_instructions(RRB, rec, count, first);
			i --;
		}
		rec->count = 0;
		i = 0;
	}
	find_lower(rec, count);
}

void	find_lower(t_rec *rec, t_count *count)
{
	int	i;	
	int lower_value;
	int	hold_then_value;

	lower_value = rec->stack_a[0];
	i = 1;
	rec->lower = 0;
	if (count->count_a > 1)
		hold_then_value= rec->stack_a[1];
	while (i < count->count_a)
	{
		if (lower_value > rec->stack_a[i])	
		{
			hold_then_value = lower_value;
			rec->hold_then = rec->lower;
			lower_value = rec->stack_a[i];
			rec->lower = i;
		}
		else if (hold_then_value > rec->stack_a[i])
		{
			hold_then_value = rec->stack_a[i];
			rec->hold_then = i;
		}
		i ++;
	}
	find_upper(rec, count);
}

void	find_upper(t_rec *rec, t_count *count)
{
	int i;	
	int	hold_before_value;
	int	upper_value;

	upper_value = rec->stack_a[count->count_a - 1];
	i = 1;
	rec->upper = 0;
	if (count->count_a > 1)
		hold_before_value = rec->stack_a[1];
	while (i < count->count_a)
	{
		if (upper_value > rec->stack_a[i])	
		{
			hold_before_value = upper_value;
			rec->hold_before = rec->upper;
			upper_value = rec->stack_a[i];
			rec->upper = i;
		}
		else if (hold_before_value > rec->stack_a[i])
		{
			hold__value = rec->stack_a[i];
			rec->hold_before = i;
		}
		i ++;
	}
}

void	check_push(t_rec *rec, t_count *count)
{
	if (rec->lower >= count->count_a / 2)
	{
		rec->nbr_move_lower = count->count_a - rec->lower;
		rec->move_lower = RRA;
	}
	else if (rec->lower < count->count_a / 2)
	{
		rec->nbr_move_lower = rec->lower;
		rec->move_lower = RA;
	}
	if (rec->hold_then >= count->count_a / 2)
	{
		rec->nbr_move_hold = count->count_a - rec->hold_then;
		rec->move_hold_then = RRA;
	}
	else if (rec->hold_then < count->count_a / 2)
	{
		rec->nbr_move_hold = rec->hold_then;
		rec->move_hold_then = RA;
	}
	check_push2(rec, count);
}

void	check_push2(t_rec *rec, t_count *count)
{
	if (rec->upper >= count->count_a / 2)
	{
		rec->nbr_move_upper = count->count_a - rec->upper;
		rec->move_upper = RRA;
	}
	else if (rec->upper < count->count_a / 2)
	{
		rec->nbr_move_upper = rec->upper;
		rec->move_upper = RA;
	}
	if (rec->hold_before >= count->count_a / 2)
	{
		rec->nbr_move_hold = count->count_a - rec->hold_before;
		rec->move_hold_before = RRA;
	}
	else if (rec->hold_before < count->count_a / 2)
	{
		rec->nbr_move_hold = rec->hold_before;
		rec->move_hold_before = RA;
	}
}
