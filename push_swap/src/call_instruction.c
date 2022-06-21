/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:26:58 by eedy              #+#    #+#             */
/*   Updated: 2022/06/21 13:26:20 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	instruction2(int nbr_cout, t_rec *rec, t_count *count, t_lists *first)
{
	(void)nbr_cout;
	if (rec->k_cp == PA)	
	{
		pa(rec->cp_a, rec->cp_b, count);
			add_new_list(first, "pa", 4);
	}
	if (rec->k_cp == PB)	
	{
		pb(rec->cp_a, rec->cp_b, count);
			add_new_list(first, "pb", 4);
	}
	if (rec->k_cp == RRA)	
	{
		rra(rec->cp_a, count);
			add_new_list(first, "rra", 4);
	}
	instruction3(nbr_cout, rec, count, first);
}

void	instruction3(int nbr_cout, t_rec *rec, t_count *count, t_lists *first)
{
	(void)nbr_cout;
	if (rec->k_cp == RRB)	
	{
		rrb(rec->cp_b, count);
			add_new_list(first, "rrb", 4);
	}
	if (rec->k_cp == RRR)	
	{
		rrr(rec->cp_a, rec->cp_b, count);
			add_new_list(first, "rrr", 4);
	}
	if (rec->k_cp == RA)	
	{
		ra(rec->cp_a, count);
			add_new_list(first, "ra", 4);
	}
	instruction4(nbr_cout, rec, count, first);
}

void	instruction4(int nbr_cout, t_rec *rec, t_count *count, t_lists *first)
{
	(void)nbr_cout;
	if (rec->k_cp == RB)	
	{
		rb(rec->cp_b, count);
		add_new_list(first, "rb", 4);
	}
	if (rec->k_cp == RR)	
	{
		rr(rec->cp_a, rec->cp_b, count);
		add_new_list(first, "rr", 4);
	}
}
