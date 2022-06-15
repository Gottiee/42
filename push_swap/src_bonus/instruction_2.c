/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:23:32 by eedy              #+#    #+#             */
/*   Updated: 2022/06/15 11:48:51 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(int *stack_a, int *stack_b, t_count *count)
{
	int	tmp;
	int	tmp_cur;
	int	i;

	if (count->count_a == 0 )
		return ;
	if (count->count_b != 0)
		tmp = stack_b[0];
	i = 1;
	while (i <= count->count_b)
	{
		tmp_cur = tmp;
		tmp = stack_b[i];
		stack_b[i] = tmp_cur;
		i ++;
	}
	stack_b[0] = stack_a;
	up_stack(stack_a, count)
	count->count_b++;
	count->count_a--;
}

void	up_stack_a(int *stack_a, t_count *count)
{
	int	i;

	i = count->count_a;
	tmp = stack_a[i];
	i --;
	while (i >= 0)
	{
		tmp_cur = tmp;
		tmp = stack_a[i];
		stack_a[i] = tmp_cur;
		i --;
	}
}

void	rra(int *stack_a, t_count *count)
{
	int	i;

	if (count->count_a == 0)
		return ;
	tmp = stack_a[0];
	stack_a[0] = stack_a[count->count_a];
	i = 1;
	while (i < count->count_a)
	{
		tmp_cur = tmp;
		tmp = stack_a[i];
		stack_a[i] = tmp_cur;
		i ++;
	}
}

void	rrb(int *stack_b, t_count *count)
{
	int	i;

	if (count->count_b == 0)
		return ;
	tmp = stack_b[0];
	stack_b[0] = stack_b[count->count_b];
	i = 1;
	while (i < count->count_b)
	{
		tmp_cur = tmp;
		tmp = stack_b[i];
		stack_b[i] = tmp_cur;
		i ++;
	}
}

void	rrr(int *stack_a, int *stack_b, t_count *count)
{
	rra(stack_a, count);
	rrb(stack_b, count);
}
