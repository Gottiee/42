/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:06:53 by eedy              #+#    #+#             */
/*   Updated: 2022/06/17 20:06:23 by eedy             ###   ########.fr       */
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

void	replace_list(int nbr_cout, char *buffer, int malloc_size, t_lists *first)
{
	int 	i;
	t_lists	*tmp;

	i = 0;
	tmp = first;
	while (i < nbr_cout)
	{
		tmp = tmp->next;
		i ++;
	}
	ft_strlcpy(tmp->move, buffer, malloc_size);
}

void	de_list(t_lists *first)
{
	t_lists	*tmp;

	while (first)
	{
		tmp = first;
		first = first -> next;
		free(tmp->move);
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
