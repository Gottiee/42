/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:06:53 by eedy              #+#    #+#             */
/*   Updated: 2022/06/22 12:00:07 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lists	*init_list(void)
{
	t_lists	*first;

	first = malloc(sizeof(t_lists));
	if (!first)
		return (NULL);
	first -> next = NULL;
	return (first);
}

int	add_new_list(t_lists *first, char *buffer, int malloc_size)
{
	t_lists	*new;
	t_lists	*tmp;

	new = malloc(sizeof(t_lists));
	new->move = malloc(sizeof(char) * malloc_size);
	first->count_cout++;
	ft_strlcpy(new->move, buffer, malloc_size);
	tmp = first;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
	new -> next = NULL;
	return (1);
}

void	de_list(t_lists *first)
{
	t_lists	*tmp;
	int		boolean;

	boolean = 0;
	while (first)
	{
		tmp = first;
		first = first -> next;
		if (boolean != 0)
			if (tmp->move)
				free(tmp->move);
		boolean ++;
		free(tmp);
	}
}

void	print_solution(t_lists *first)
{
	t_lists	*tmp;

	tmp = first->next;
	while (tmp)
	{
		ft_printf("%s\n", tmp->move);
		tmp = tmp->next;
	}
}

void	del_move(t_lists *first, t_rec *rec)
{
	t_lists	*tmp;	
	t_lists	*tmp2;
	int		i;

	tmp = first;
	i = 1;
	while (i < rec->cout)
	{
		tmp = tmp->next;
		i ++;
	}
	tmp2 = tmp->next;
	free(tmp2->move);
	free(tmp2);
	tmp->next = NULL;
}
