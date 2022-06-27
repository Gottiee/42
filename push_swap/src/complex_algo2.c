/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:12:54 by eedy              #+#    #+#             */
/*   Updated: 2022/06/27 16:58:12 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_chunck_a(int size_chunck, t_rec *rec, t_lists *first, t_count *count)
{
	int	i;

	i = 0;
	while (i < size_chunck / 2)
	{
		if (rec->stack_b[0] > rec->mid_value)
		{
			call_instructions(PA, rec, count, first);
			i ++;
		}
		else
			call_instructions(RB, rec, count, first);
	}
	return (i);	
}

int	*sort_chunck(int	*chunck, int pushed)
{
	int	*cp_stack;
	int	i;	
	int	j;
	int	min;
	int tmp;
	
	cp_stack = malloc(sizeof(int) * (pushed + 1));
	copy_chunck(cp_stack, chunck, pushed);
	i = 0;
	while (i < pushed)
	{
		min = i;
		j = i + 1;
		while (j < pushed)
		{
			if (cp_stack[j] < cp_stack[min])
				min = j;
			j ++;	
		}
		tmp = cp_stack[min];
		cp_stack[min] = cp_stack[i];
		cp_stack[i] = tmp;
		i ++;
	}
	return(cp_stack);
}

int	verif_sort_chunck(int *cp_chunck, int pushed)
{
	int max_nbr;
	int	i;

	max_nbr = cp_chunck[0];
	i = 1;	
	while (i < pushed)
	{
		if (cp_chunck[i] > max_nbr)
			return (0);
		max_nbr = cp_chunck[i];
		i ++;
	}
	return (1);	
}

void	copy_chunck(int *cp_chunck, int *stack, int pushed)
{
	int	i;	

	i = 0;
	while (i < pushed)
	{
		cp_chunck[i] = stack[i];
		i++;
	}
}
