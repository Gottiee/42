/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:12:54 by eedy              #+#    #+#             */
/*   Updated: 2022/06/24 18:30:21 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	manage_upper(t_rec *rec, t_count *count, t_lists *first)
{
	
}

int	manage_move(t_rec *rec, t_count *count)
{
	if (rec->nbr_move_lower <= rec->nbr_move_hold
		&& rec->nbr_move_lower <= rec->nbr_move_upper
		&& rec->nbr_move_lower <= rec->nbr_move_before)
		return (1);
	else if (rec->nbr_move_hold < rec->nbr_move_lower
		&& rec->nbr_move_hold < rec->nbr_move_upper
		&& rec->nbr_move_hold < rec->nbr_move_before)
		return (2);
	else if (rec->nbr_move_upper < rec->nbr_move_lower
		&& rec->nbr_move_upper < rec->nbr_move_hold
		&& rec->nbr_move_upper < rec->nbr_move_before)
		return (3);
	else
		return (4);
}

void	manage_hold_then(t_rec *rec, t_count *count, t_lists *first)
{
	int i

	i = 0;
	if (rec->nbr_move_lower > rec->nbr_move_hold && count->count_a != 1)
	{
		while (i < rec->nbr_move_hold)
		{
			call_instructions(rec->move_hold_then, rec, count, first);
			i ++;
		}
		i = 0;
		call_instructions(PB, rec, count, first);
		rec->count++;
	}
}
