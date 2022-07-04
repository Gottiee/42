/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:02:20 by eedy              #+#    #+#             */
/*   Updated: 2022/07/04 14:21:05 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	egual2(t_rec *rec, t_lists *first, t_count *count)
{
	if (rec->stack_b[0] < rec->stack_b[1])
		call_instructions(SB, rec, count, first);
	call_instructions(PA, rec, count, first);
	call_instructions(PA, rec, count, first);
}

int	ver(int size_chunck, t_rec *rec, t_lists *first, t_count *count)
{
	if (verif_tab(rec->stack_a, count) || size_chunck == 2)
	{
		if (rec->stack_a[0] > rec->stack_a[1])
			call_instructions(SA, rec, count, first);
		rec->bolo = 1;
		return (1);
	}
	return (0);
}

int	ty_n(int *size_chunck, t_rec *rec, t_lists *first, t_count *count)
{
	int	*cp_stack;
	int	pushed;

	cp_stack = sort_chunck(rec->stack_a, *size_chunck);
	rec->mid_value = cp_stack[*size_chunck / 2];
	pushed = push(*size_chunck, rec, first, count);
	*size_chunck -= pushed;
	one(*size_chunck, count, rec, first);
	free(cp_stack);
	return (pushed);
}
