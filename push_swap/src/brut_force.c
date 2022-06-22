/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut_force.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:45:21 by eedy              #+#    #+#             */
/*   Updated: 2022/06/22 12:03:56 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	brut_center(int *stack_a, int *stack_b, t_count *count, int argc)
{
	t_lists	*first;
	t_rec	rec;
	(void)stack_b;

	rec.cout = 0;
	rec.argc = argc;
	rec.nbr_cout = 1;
	first = init_list();

	rec.cp_a = malloc(sizeof(int) * (argc + 1));
	rec.cp_cp_a = malloc(sizeof(int) * (argc + 1));
	rec.cp_b = malloc(sizeof(int) * (argc + 1));
	rec.cp_cp_b = malloc(sizeof(int) * (argc + 1));
	count->before_a = count->count_a;
	count->before_b = count->count_b;
	copy_a(rec.cp_a, stack_a, count);
	while(!back_track(rec.nbr_cout, &rec, count, first))
	{
		rec.nbr_cout++;
		rec.cout = 0;
	}
	print_solution(first);
	de_list(first);
	free(rec.cp_a);
	free(rec.cp_b);
	free(rec.cp_cp_b);
	free(rec.cp_cp_a);
}

int	back_track(int nbr_cout, t_rec *rec, t_count *count, t_lists *first)
{
	int	k;
	int	*b;
	int	*a;
	int	before_a;
	int	before_b;

	b = malloc(sizeof(int) * (rec->argc + 1));
	a = malloc(sizeof(int) * (rec->argc + 1));
	k = 2;
	if (verif_tab(rec->cp_a, count))
	{
		free(a);
		free(b);
		return(1);
	}
	while (k <= 12)
	{
		rec->k_cp = k;
		if (verif_move(nbr_cout, rec->cout))
		{
			before_a = count->count_a;
			before_b = count->count_b;
			copy_a(a, rec->cp_a, count);
			copy_b(b, rec->cp_b, count);
			call_instructions(nbr_cout, rec, count, first);
			rec->cout++;
			if (back_track(nbr_cout, rec, count, first))
			{
				free(a);
				free(b);
				return (1);
			}
			count->count_a = before_a;
			count->count_b = before_b;
			copy_a(rec->cp_cp_a, a, count);
			copy_b(rec->cp_cp_b, b, count);
			cancel_k(rec, count, first);
			rec->cout--;
		}
		k ++;
	}
	free(a);
	free(b);
	return (0);
}

int	verif_move(int i, int cout)
{
	if (cout >= i)
		return(0);
	return(1);
}

void	cancel_k(t_rec *rec, t_count *count, t_lists *first)
{
	copy_a(rec->cp_a, rec->cp_cp_a, count);
	copy_b(rec->cp_b, rec->cp_cp_b, count);
	del_move(first, rec);
}

void	call_instructions(int nbr_cout, t_rec *rec, t_count *count, t_lists *first)
{
	if (rec->k_cp == SA)	
	{
		sa(rec->cp_a, count);
			add_new_list(first, "sa", 4);
	}
	if (rec->k_cp == SB)	
	{
		sb(rec->cp_b, count);
			add_new_list(first, "sb", 4);
	}
	if (rec->k_cp == SS)	
	{
		ss(rec->cp_a, rec->cp_b, count);
			add_new_list(first, "ss", 4);
	}
	instruction2(nbr_cout, rec, count, first);
}
