/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:14:38 by eedy              #+#    #+#             */
/*   Updated: 2022/05/05 13:29:57 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
		tmp = tmp -> next;
	new -> next = NULL;
	new = tmp;
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_list *list;
	int a = 0;
	int b = 1;

	t_list *first;
	list = malloc(sizeof(t_list));
	first = list;
	list -> content = &a;
	list -> next = NULL;
	t_list *new;
	new = malloc(sizeof(t_list));
	new -> content = &b;
	ft_lstadd_back(&first, new);

	while (first)
	{
		printf("%d -> ", *((int *)(first -> content)));
		first = first -> next;
	}
	printf("\n");
}*/
