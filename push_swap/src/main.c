/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:56:08 by eedy              #+#    #+#             */
/*   Updated: 2022/07/11 17:50:21 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_count	count;
	t_lists	*first;
	t_rec	rec;

	if (argc == 1)
		return (0);
	rec.stack_a = arg_parsing(argc, argv);
	if (!rec.stack_a)
		return (0);
	rec.argc = argc;
	rec.bolo = 0;
	count.count_a = argc - 1;
	count.count_b = 0;
	if (verif_tab(rec.stack_a, &count))
		return (0);
	first = init_list();
	rec.stack_b = malloc(sizeof(int) * (argc + 1));
	if (!first || !rec.stack_b)
	{
		free(rec.stack_b);
		free(rec.stack_a);
		return (0);
	}
	main2(argc, &count, &rec, first);
}

void	main2(int argc, t_count *count, t_rec *rec, t_lists *first)
{
	if (argc <= 4)
		small_algo(count, rec, first);
	else
		one(argc - 1, count, rec, first);
	free(rec->stack_a);
	free(rec->stack_b);
	print_solution(first);
	de_list(first);
}
