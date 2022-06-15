/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:56:08 by eedy              #+#    #+#             */
/*   Updated: 2022/06/15 16:32:51 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	t_count	count;

	count.count_a = argc - 1;
	count.count_b = 0;
	(void)stack_a;
	(void)stack_b;
	(void)count;
	if (argc == 1)
		return (0);
	stack_a = arg_parsing(argc, argv);
	printf("sa\n");
}
