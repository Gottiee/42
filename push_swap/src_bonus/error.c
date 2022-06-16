/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:18:22 by eedy              #+#    #+#             */
/*   Updated: 2022/06/16 15:06:59 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	end_center(int event, ...)
{
	va_list	ptr;		

	va_start(ptr, event);
	if (event == ERROR_ARG)
		error_arg(ptr);
	if (event == TAB_PRB)
		free_2_stacks(ptr);
	if (event == WIN)
		win(ptr);
}

void	free_2_stacks(va_list ptr)
{
	int	*stack_a;	
	int	*stack_b;

	stack_a = va_arg(ptr, int *);
	stack_b = va_arg(ptr, int *);
	free(stack_a);
	free(stack_b);
	ft_printf("____________________________________________________");
	ft_printf("\n                      KO\n");
	exit(1);
}

void	win(va_list ptr)
{
	int	*stack_a;	
	int	*stack_b;

	stack_a = va_arg(ptr, int *);
	stack_b = va_arg(ptr, int *);
	free(stack_a);
	free(stack_b);
	ft_printf("____________________________________________________");
	ft_printf("\n                      OK\n");
	exit(1);

}

void	error_arg(va_list ptr)
{
	int	*tab;

	tab = va_arg(ptr, int *);
	free(tab);
	ft_printf("Error\n");
	exit(1);
}
