/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:12:14 by eedy              #+#    #+#             */
/*   Updated: 2022/06/15 14:26:39 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_arg(char *str, int *stack)
{
	int		i;
	int		bolo;
	long	nbr;

	bolo = 1;
	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == '-')
			bolo = -1;
		i += (str[i] == '-');
		if (str[i] < '0' || str[i] > '9')
			end_center(ERROR_ARG, stack);
		i ++;
	}
	i = (bolo == -1);
	while (str[i])
	{
		nbr = nbr * 10 + str[i] - '0';
		i ++;
	}
	nbr *= bolo;
	if (nbr > 2147483647 || nbr < -2147483648)
		end_center(ERROR_ARG, stack);
}

void	fill_tab(int *stack, char **argv, int argc)
{
	int i;
	int	k;

	i = 1;
	while (argv[i])	
	{
		check_arg(argv[i], stack);
		stack[i - 1] = ft_atoi(argv[i]);
		i ++;
	}
	i = 0;
	while (i < argc - 1)
	{
		k = i + 1;
		while (k < argc - 1)
		{
			if (stack[i] == stack[k])
				end_center(ERROR_ARG, stack);
			k ++;
		}
		i ++;
	}
}

int *arg_parsing(int argc, char **argv)
{
	int	*stack_a;

	stack_a = malloc(sizeof(int) * (argc));
	fill_tab(stack_a, argv, argc);
	return (stack_a);
}
