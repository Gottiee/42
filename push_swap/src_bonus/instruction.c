/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:21:34 by eedy              #+#    #+#             */
/*   Updated: 2022/07/04 14:54:38 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	sa(int *stack_a, t_count *count)
{
	int	tmp;

	if (count->count_a == 1)
		return ;
	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
}

void	sb(int *stack_b, t_count *count)
{
	int	tmp;

	if (count->count_b == 0 || count->count_b == 1)
		return ;
	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
}

void	ss(int *stack_a, int *stack_b, t_count *count)
{
	sa(stack_a, count);
	sb(stack_b, count);
}

void	pa(int *stack_a, int *stack_b, t_count *count)
{
	int	tmp;
	int	tmp_cur;
	int	i;

	if (count->count_b == 0)
		return ;
	if (count->count_a != 0)
		tmp = stack_a[0];
	i = 1;
	while (i <= count->count_a)
	{
		tmp_cur = tmp;
		tmp = stack_a[i];
		stack_a[i] = tmp_cur;
		i ++;
	}
	stack_a[0] = stack_b[0];
	up_stack_b(stack_b, count);
	count->count_a++;
	count->count_b--;
}

void	up_stack_b(int *stack_b, t_count *count)
{
	int	i;
	int	tmp_cur;
	int	tmp;

	i = count->count_b;
	tmp = stack_b[i];
	i --;
	while (i >= 0)
	{
		tmp_cur = tmp;
		tmp = stack_b[i];
		stack_b[i] = tmp_cur;
		i --;
	}
}
