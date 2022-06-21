/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:26:58 by eedy              #+#    #+#             */
/*   Updated: 2022/06/21 12:19:55 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	instruction2(int nbr_cout, t_rec *rec, t_count *count, t_lists *first)
{
	if (rec->k_cp == PA)	
	{
		pa(rec->cp_a, rec->cp_b, count);
		if (nbr_cout > first->count_cout)
			add_new_list(first, "pa", 4);
		else
			replace_list(nbr_cout, "pa", 4, first);
	}
	if (rec->k_cp == PB)	
	{
		pb(rec->cp_a, rec->cp_b, count);
		if (nbr_cout > first->count_cout)
			add_new_list(first, "pb", 4);
		else
			replace_list(nbr_cout, "pb", 4, first);
	}
	if (rec->k_cp == RRA)	
	{
		rra(rec->cp_a, count);
		if (nbr_cout > first->count_cout)
			add_new_list(first, "rra", 4);
		else
			replace_list(nbr_cout, "rra", 4, first);
	}
	instruction3(nbr_cout, rec, count, first);
}

void	instruction3(int nbr_cout, t_rec *rec, t_count *count, t_lists *first)
{
	if (rec->k_cp == RRB)	
	{
		rrb(rec->cp_b, count);
		if (nbr_cout > first->count_cout)
			add_new_list(first, "rrb", 4);
		else
			replace_list(nbr_cout, "rrb", 4, first);
	}
	if (rec->k_cp == RRR)	
	{
		rrr(rec->cp_a, rec->cp_b, count);
		if (nbr_cout > first->count_cout)
			add_new_list(first, "rrr", 4);
		else
			replace_list(nbr_cout, "rrr", 4, first);
	}
	if (rec->k_cp == RA)	
	{
		ra(rec->cp_a, count);
		if (nbr_cout > first->count_cout)
			add_new_list(first, "ra", 4);
		else
			replace_list(nbr_cout, "ra", 4, first);
	}
	instruction4(nbr_cout, rec, count, first);
}

void	instruction4(int nbr_cout, t_rec *rec, t_count *count, t_lists *first)
{
	if (rec->k_cp == RB)	
	{
		rb(rec->cp_b, count);
		if (nbr_cout > first->count_cout)
			add_new_list(first, "rb", 4);
		else
			replace_list(nbr_cout, "rb", 4, first);
	}
	if (rec->k_cp == RR)	
	{
		rr(rec->cp_a, rec->cp_b, count);
		if (nbr_cout > first->count_cout)
			add_new_list(first, "rr", 4);
		else
			replace_list(nbr_cout, "rr", 4, first);
	}
}
