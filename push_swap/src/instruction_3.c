/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:40:50 by eedy              #+#    #+#             */
/*   Updated: 2022/06/16 12:32:54 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(int *stack_a, t_count *count)
{
	int	i;
	int	tmp;
	int	tmp_cur;

	if (count->count_a == 0)
		return ;
	tmp = stack_a[count->count_a - 1];
	stack_a[count->count_a - 1] = stack_a[0];
	i = count->count_a - 2;
	while (i >= 0)
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
	int	tmp;
	int	tmp_cur;

	if (count->count_b == 0)
		return ;
	tmp = stack_b[count->count_b - 1];
	stack_b[count->count_b - 1] = stack_b[0];
	i = count->count_b - 2;
	while (i >= 0)
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
