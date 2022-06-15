/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:40:50 by eedy              #+#    #+#             */
/*   Updated: 2022/06/15 11:48:47 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(int *stack_a, t_count *count)
{
	int	i;

	if (count->count_a == 0)
		return ;
	tmp = stack_a[count->count_a];
	stack_a[count->count_a] = stack_a[0];
	i = count->count_a - 1;
	while (i > 0)
	{
		tmp_cur = tmp;
		tmp = stack_a[i];
		stack_a[i] = tmp_cur;
		i --;
	}
}

void	rb(int *stack_b, t_count *count)
{
	int	i;

	if (count->count_b == 0)
		return ;
	tmp = stack_b[count->count_b];
	stack_b[count->count_b] = stack_b[0];
	i = count->count_b - 1;
	while (i > 0)
	{
		tmp_cur = tmp;
		tmp = stack_b[i];
		stack_b[i] = tmp_cur;
		i --;
	}
}

void	rr(int *stack_a, int *stack_b, t_count *count)
{
	ra(stack_a, count);
	rb(stack_b, count);
}
