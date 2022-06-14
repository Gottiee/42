/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intruction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:21:34 by eedy              #+#    #+#             */
/*   Updated: 2022/06/14 19:15:27 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sa(int *stack_a, t_count *count)
{
	int	tmp;

	if (count->count_a == 1)
		return ;
	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
}

void	sb(int stack_b, t_count *count)
{
	if (count->count_b == 0 || count->count_b == 1)
		return ;
	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
}

void	ss(int stack_a, int stack_b, t_count *count)
{
	sa(stack_a, count);
	sb(stack_b, count);
}

void	pa(int stack_a, int stack_b, t_count count)
{
	int	tmp;
	int	tmp_cur;
	int	i;

	i = 0;
	if (count->count_b == 0)
		return ;
	while (i + 1< count->count_a)
	{
		if (i == 0)
			tmp = stack_a[i];
		tmp_cur = tmp;
		tmp = stack_a[i + 1];
		stack_a[i] = tmp_cur;
	}

}
