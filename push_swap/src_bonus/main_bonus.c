/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:07:08 by eedy              #+#    #+#             */
/*   Updated: 2022/06/15 12:58:51 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	t_count	count;

	count.count_a = argc - 1;
	count.count_b = 0;
	if (argc == 1)
		return (0);
	stack_a = arg_parsing(argc, argv);
	stack_b = malloc(sizeof(int) * argc)
	read_terminal(stack_a, stack_b, &count);
}

void	read_terminal(int *stack_a, int *stack_b, t_count * count)
{
	int		fd;	
	int		i;
	char	buf[1000];

	i = 0; 
	while (verif_buf(buf, i))
	{
		while (1)
		{
			read(0, &buf, 1)
			if (buf[i] == \n)
				break;
			i ++;
		}
		send_instruction(stack_a, stack_b, count, buf);
	}
}

int	verif_buf(char *buf, int i)
{
	if (i == 0)
		return(1);
	i = 0;
	if (buf[i] == 's')
		i = check_s(buf);
	else if (buf[i] == 'p')
		i = check_p(buf);
	else if (buf[i] == 'r')
		i = check_r(buf);
	else
		i = check_else(buf);
	}
	return(i);
}
