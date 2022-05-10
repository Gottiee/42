/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:14:38 by eedy              #+#    #+#             */
/*   Updated: 2022/05/10 13:21:06 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
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
