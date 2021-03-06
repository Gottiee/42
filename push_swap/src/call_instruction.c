/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:44:41 by eedy              #+#    #+#             */
/*   Updated: 2022/07/11 17:09:00 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	call_instructions(int k, t_rec *rec, t_count *count, t_lists *first)
{
	int	status;

	status = 1;
	if (k == SA)
	{
		sa(rec->stack_a, count);
		status = add_new_list(first, "sa", 4);
	}
	if (k == SB)
	{
		sb(rec->stack_b, count);
		status = add_new_list(first, "sb", 4);
	}
	if (k == SS)
	{
		ss(rec->stack_a, rec->stack_b, count);
		status = add_new_list(first, "ss", 4);
	}
	if (status == 0)
	{
		ft_printf("malloc error ine list\n");
		exit(1);
	}
	instruction2(k, rec, count, first);
}

void	instruction2(int k, t_rec *rec, t_count *count, t_lists *first)
{
	int	status;

	status = 1;
	if (k == PA)
	{
		pa(rec->stack_a, rec->stack_b, count);
		status = add_new_list(first, "pa", 4);
	}
	if (k == PB)
	{
		pb(rec->stack_a, rec->stack_b, count);
		status = add_new_list(first, "pb", 4);
	}
	if (k == RRA)
	{
		rra(rec->stack_a, count);
		status = add_new_list(first, "rra", 4);
	}
	if (status == 0)
	{
		ft_printf("malloc error ine list\n");
		exit(1);
	}
	instruction3(k, rec, count, first);
}

void	instruction3(int k, t_rec *rec, t_count *count, t_lists *first)
{
	int	status;

	status = 1;
	if (k == RRB)
	{
		rrb(rec->stack_b, count);
		status = add_new_list(first, "rrb", 4);
	}
	if (k == RRR)
	{
		rrr(rec->stack_a, rec->stack_b, count);
		status = add_new_list(first, "rrr", 4);
	}
	if (k == RA)
	{
		ra(rec->stack_a, count);
		status = add_new_list(first, "ra", 4);
	}
	if (status == 0)
	{
		ft_printf("malloc error ine list\n");
		exit(1);
	}
	instruction4(k, rec, count, first);
}

void	instruction4(int k, t_rec *rec, t_count *count, t_lists *first)
{
	int	status;

	status = 1;
	if (k == RB)
	{
		rb(rec->stack_b, count);
		status = add_new_list(first, "rb", 4);
	}
	if (k == RR)
	{
		rr(rec->stack_a, rec->stack_b, count);
		status = add_new_list(first, "rr", 4);
	}
	if (status == 0)
	{
		ft_printf("malloc error ine list\n");
		exit(1);
	}
}
