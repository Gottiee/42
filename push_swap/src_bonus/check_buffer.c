/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:05:04 by eedy              #+#    #+#             */
/*   Updated: 2022/07/04 14:50:39 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	check_s(char *buf, int *stack_a, int *stack_b, t_count *count)
{
	if (buf[count->i + 1] == 'a')
	{
		count->nbr++;
		sa(stack_a, count);
		ft_printf("\nInstruction number : %d         mov:sa\n\n", count->nbr);
		print_stack(stack_a, stack_b, count);
	}
	else if (buf[count->i + 1] == 'b')
	{
		count->nbr++;
		sb(stack_b, count);
		ft_printf("\nInstruction number : %d         mov:sb\n\n", count->nbr);
		print_stack(stack_a, stack_b, count);
	}
	else
	{
		count->nbr++;
		ss(stack_a, stack_b, count);
		ft_printf("\nInstruction number : %d         mov:ss\n\n", count->nbr);
		print_stack(stack_a, stack_b, count);
	}
	return (3);
}

int	check_p(char *buf, int *stack_a, int *stack_b, t_count *count)
{
	if (buf[count->i + 1] == 'a')
	{
		count->nbr++;
		pa(stack_a, stack_b, count);
		ft_printf("\nInstruction number : %d         mov:pa\n\n", count->nbr);
		print_stack(stack_a, stack_b, count);
	}
	else if (buf[count->i + 1] == 'b')
	{
		count->nbr++;
		pb(stack_a, stack_b, count);
		ft_printf("\nInstruction number : %d         mov:pb\n\n", count->nbr);
		print_stack(stack_a, stack_b, count);
	}
	return (3);
}

int	check_r(char *buf, int *stack_a, int *stack_b, t_count *count)
{
	if (buf[count->i + 1] == 'a')
	{
		count->nbr++;
		ra(stack_a, count);
		ft_printf("\nInstruction number : %d         mov:ra\n\n", count->nbr);
		print_stack(stack_a, stack_b, count);
	}
	else if (buf[count->i + 1] == 'b')
		norm(stack_a, stack_b, count);
	else if (buf[count->i + 1] == 'r')
	{
		if (buf[count->i + 2] != '\n')
		{
			check_r2(buf, stack_a, stack_b, count);
			return (4);
		}
		count->nbr++;
		rr(stack_a, stack_b, count);
		ft_printf("\nInstruction number : %d         mov:rr\n\n", count->nbr);
		print_stack(stack_a, stack_b, count);
	}
	return (3);
}

void	norm(int *stack_a, int *stack_b, t_count *count)
{
	count->nbr++;
	rb(stack_b, count);
	ft_printf("\nInstruction number : %d         mov:rb\n\n", count->nbr);
	print_stack(stack_a, stack_b, count);
}

void	check_r2(char *buf, int *stack_a, int *stack_b, t_count *count)
{
	if (buf[count->i + 2] == 'a')
	{
		count->nbr++;
		rra(stack_a, count);
		ft_printf("\nInstruction number : %d         mov:rra\n\n", count->nbr);
		print_stack(stack_a, stack_b, count);
	}
	else if (buf[count->i + 2] == 'b')
	{
		count->nbr++;
		rrb(stack_b, count);
		ft_printf("\nInstruction number : %d         mov:rrb\n\n", count->nbr);
		print_stack(stack_a, stack_b, count);
	}
	else if (buf[count->i + 2] == 'r')
	{
		count->nbr++;
		rrr(stack_a, stack_b, count);
		ft_printf("\nInstruction number : %d         mov:rrr\n\n", count->nbr);
		print_stack(stack_a, stack_b, count);
	}
}
