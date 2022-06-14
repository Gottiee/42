/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:38:00 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 19:16:51 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)-> content);
		tmp = (*lst);
		(*lst) = (*lst)-> next;
		free(tmp);
	}
}

/*#include <stdio.h>
#include <stdlib.h>
void	delet(void *address)
{
	address = NULL;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_list *lst;
	t_list *lst2;
	t_list *first;
	int a = 1;
	int b = 2;

	lst2 = malloc(sizeof(t_list));
	lst = malloc(sizeof(t_list));
	lst -> next = lst2;
	lst -> content = &a;
	lst2 -> next = NULL;
	lst2 -> content = &b;
	first = lst;
	
	while (first)
	{
		printf("%d -> ", *((int *)(first -> content)));
		first = first -> next;
	}
	printf("NULL\n");
	ft_lstclear(&lst, &delet);
	first = lst;
	while (first)
	{
		printf("%d -> ", *((int *)(first -> content)));
		first = first -> next;
	}
	printf("NULL\n");
}*/
