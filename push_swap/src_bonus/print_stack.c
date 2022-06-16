/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:51:07 by eedy              #+#    #+#             */
/*   Updated: 2022/06/16 12:00:22 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	print_b(int * stack_b, t_count *count, int i)
{
	int	k;
	int nbr_len;

	if (i >= count->count_a)
	{
		ft_printf("|              |");
		k = 0;
		while (k++ < 16)
		ft_printf(" ");
		if (i < count->count_b)
		{
			nbr_len = ft_strlen(ft_itoa(stack_b[i]));
			ft_printf("| %d", stack_b[i]);
			nbr_len = 12 - nbr_len;
			while (nbr_len-- > -1)
				ft_printf(" ");
			ft_printf("|\n");
		}
		else
			ft_printf("|              |\n");
	}
	return (1);
}

int	print_a(int *stack_a, int * stack_b, t_count *count, int i)
{
	int	nbr_len;
	int	k;

	if (i < count->count_a)
	{
		nbr_len = ft_strlen(ft_itoa(stack_a[i]));
		ft_printf("| %d", stack_a[i]);
		nbr_len = 12 - nbr_len;
		while (nbr_len-- > -1)
			ft_printf(" ");
		ft_printf("|");
		k = 0;
		while (k++ < 16)
		ft_printf(" ");
		if (i < count->count_b)
			print_a2(stack_b, i);
		else
			ft_printf("|              |\n");
	}
	return (print_b(stack_b, count, i));
}

void	print_a2(int * stack_b, int i)
{
	int nbr_len;

	nbr_len = ft_strlen(ft_itoa(stack_b[i]));
	ft_printf("| %d", stack_b[i]);
	nbr_len = 12 - nbr_len;
	while (nbr_len-- > -1)
	ft_printf(" ");
	ft_printf("|\n");
}

void	utils_stack(void)
{
	int i;

	i = 0;
	while (i++ < 16)
		ft_printf("-");
	i = 0;
	while (i++ < 16)
		ft_printf(" ");
	i = 0;
	while (i++ < 16)
		ft_printf("-");
	i = 0;
	ft_printf("\n");
}

void	print_stack(int *stack_a, int * stack_b, t_count *count)
{
	int i;

	i = 0;
	ft_printf("      a                                b\n\n");
	while (i++ < 16)
		ft_printf("_");
	i = 0;
	while (i++ < 16)
		ft_printf(" ");
	i = 0;
	while (i++ < 16)
		ft_printf("_");
	i = 0;
	ft_printf("\n");
	while (i < count->arg)
		i += print_a(stack_a, stack_b, count, i);
	utils_stack();
}
