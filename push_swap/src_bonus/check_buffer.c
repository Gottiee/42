/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:05:04 by eedy              #+#    #+#             */
/*   Updated: 2022/06/15 16:36:04 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	check_s(char *buf, int *stack_a, int * stack_b, t_count *count)
{
	if (buf[count->i + 1] == 'a')	
	{
		count->nbr++;
		sa(stack_a, count);
		print_stack(stack_a, stack_b, count);
	}
	return (2);
}
