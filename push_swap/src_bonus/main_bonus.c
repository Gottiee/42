/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:07:08 by eedy              #+#    #+#             */
/*   Updated: 2022/07/04 14:25:42 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	t_count	count;

	count.count_a = argc - 2;
	count.count_b = 0;
	count.i = 0;
	count.nbr = 0;
	count.arg = argc - 2;
	if (argc == 1)
		return (0);
	stack_a = arg_parsing(argc, argv);
	stack_b = malloc(sizeof(int) * (argc - 1));
	ft_printf("\nOriginal Tab :\n\n");
	print_stack(stack_a, stack_a, &count);
	verif_buf(argv[argc - 1], stack_a, stack_b, &count);
	verif_tab(stack_a, &count, stack_b);
}

void	verif_buf(char *buf, int *stack_a, int *stack_b, t_count *count)
{
	if (buf[count->i] == '\n')
		end_center(WIN, stack_a, stack_b);
	while (buf[count->i])
	{
		if (buf[count->i] == 's')
			count->i += check_s(buf, stack_a, stack_b, count);
		else if (buf[count->i] == 'p')
			count->i += check_p(buf, stack_a, stack_b, count);
		else if (buf[count->i] == 'r')
			count->i += check_r(buf, stack_a, stack_b, count);
	}
}
