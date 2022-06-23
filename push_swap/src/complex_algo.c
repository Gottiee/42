/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:22:32 by eedy              #+#    #+#             */
/*   Updated: 2022/06/23 16:07:43 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	one_undred_and_less(t_count *count, t_rec *rec, t_lists *first)
{
	int	i;

	i = 0;
	find_lower(rec, count);
	check_push(rec, count);
	while (count->count_a)
	{
		manage_lower(rec, count first);
		
		else
		{
			while (i++ <= rec->nbr_move_hold)
				call_instructions(rec->move_hold_then, count, first);
			call_instructions(PB, count, first);
			rec->count++;
			find_hold_then(rec, count);
		}
		check_push(rec, count);
	}
}

void	manage_lower(t_rec *rec, t_count *count, t_lists *first)
{
	int	 i;

	i = 0;
	if (rec->nbr_move_lower < rec->nbr_move_hold) 
		while (i++ <= rec->nbr_move_lower)
			call_instructions(rec->move_lower, count, first);
	if (rec->nbr_move_lower < rec->nbr_move_hold && rec->count == 0)
	{
		call_instructions(PB, count, first);
		find_lower(rec, count);
	}
	else if (rec->nbr_move_lower < rec->nbr_move_hold && rec->count != 0)
	{
		if (rec->count == 1)
		{
			call_instructions(PB, count, first);
			call_instructions(RA, count, first);
		}
		else
		{
			while (i++ <= rec->count)
				call_instructions(RA, count, first);
			call_instructions(PB, count, first);
			while (i-- >= 0) 
				call_instructions(RRA, count, first);
		}
	}
}

void	find_lower(t_rec *rec, t_count *count)
{
	int	i;	
	int lower_value;
	int	hold_then_value;

	lower_value = rec->stack_a[0];
	i = 1;
	rec->lower = 0;
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
}

void	find_hold_then(t_rec *rec, t_count *count)
{	
	int	i;	
	int	hold_then_value;

	hold_then_value = rec->stack_a[0];
	i = 1;
	while (i < count->count_a)
	{
		if (hold_then_value > rec->stack_a[i])
		{
			hold_then_value = rec->stack_a[i];
			rec->hold_then = i;
		}
		i ++;
	}
}

void	check_push(t_rec *rec, t_count *count)
{
	if (rec->lower > count->count_a / 2)
	{
		rec->nbr_move_lower = count->count_a - rec->lower;
		rec->move_lower = RA;
	}
	else if (rec->lower < count->count_a / 2)
	{
		rec->nbr_move_lower = rec->lower;
		rec->move_lower = RRA;
	}
	if (rec->hold_then > count->count_a / 2)
	{
		rec->nbr_move_hold = count->count_a - rec->hold_then;
		rec->move_hold_then = RA;
	}
	else if (rec->hold_then < count->count_a / 2)
	{
		rec->nbr_move_hold = rec->hold_then;
		rec->move_hold_then = RRA;
	}
}
