/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut_force.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:45:21 by eedy              #+#    #+#             */
/*   Updated: 2022/06/17 19:56:00 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	brut_center(int *stack_a, int *stack_b, t_count *count, int argc)
{
	t_lists	*first;
	t_rec	rec;

	rec.cout = 1;
	rec.nbr_cout = 1;
	first = init_list();

	rec.cp_a = malloc(sizeof(stack_a));
	rec.cp_b = malloc(sizeof(stack_b));
	copy_a(rec.cp_a, stack_a, count);
	while(!back_track(rec.nbr_cout, &rec, count, first))
	{
		rec.nbr_cout++;
		rec.cout = 0;
		count->count_a = argc - 1;
		copy_a(rec.cp_a, stack_a, count);
		if (count->count_b != 0)
		{
			free(rec.cp_b);
			rec.cp_b = malloc(sizeof(stack_b));
		}
		count->count_b = 0;
	}
	print_solution(first);
	de_list(first);
}

int	back_track(int nbr_cout, t_rec *rec, t_count *count, t_lists *first)
{
	int		k;

	k = 2;
	if (verif_tab(rec->cp_a, count))
		return(1);
	while (k <= 12)
	{
		rec->k_cp = k;
		if (verif_move(nbr_cout, rec->cout))
		{
			call_instructions(nbr_cout, rec, count, first);
			if (back_track(nbr_cout, rec, count, first))
				return (1);
			if (k == PA || k == PB)
				cancel_k(k, count);
			rec->cout--;
		}
		k ++;
	}
	return (0);
}

int	verif_move(int i, int cout)
{
	if (cout >= i)
		return(0);
	return(1);
}

void	cancel_k(int k, t_count *count)
{
	if (k == PA)
		if (count->count_b != 0) 
			count->count_b--;
	if (k == PB)
		if (count->count_a != 0)
			count->count_a--;
}

void	call_instructions(int nbr_cout, t_rec *rec, t_count *count, t_lists *first)
{
	if (rec->k_cp == SA)	
	{
		sa(rec->cp_a, count);
		if (nbr_cout > first->count_cout)
			add_new_list(first, "sa", 4);
		else
			replace_list(nbr_cout, "sa", 4, first);
	}
	if (rec->k_cp == SB)	
	{
		sb(rec->cp_b, count);
		if (nbr_cout > first->count_cout)
			add_new_list(first, "sb", 4);
		else
			replace_list(nbr_cout, "sb", 4, first);
	}
	if (rec->k_cp == SS)	
	{
		ss(rec->cp_a, rec->cp_b, count);
		if (nbr_cout > first->count_cout)
			add_new_list(first, "ss", 4);
		else
			replace_list(nbr_cout, "ss", 4, first);
	}
	instruction2(nbr_cout, rec, count, first);
}
