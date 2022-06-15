/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:51:07 by eedy              #+#    #+#             */
/*   Updated: 2022/06/15 18:16:05 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	print_stack(int *stack_a, int * stack_b, t_count *count)
{
	int i;
	int	k;
	int	nbr_len;

	i = 0;
	k = 0;
	ft_printf("\nIntrusction number : %d\n\n", count->nbr);
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
	{
		if (i < count->count_a)
		{
			nbr_len = ft_strlen(ft_itoa(stack_a[i]));
			ft_printf("| %d", stack_a[i]);
			nbr_len = 12 - nbr_len;
			while (nbr_len-- > -1)
				ft_printf(" ");
			ft_printf("|");
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
		else
		{
			ft_printf("|              |\n");
		}
		i ++;
	}
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
