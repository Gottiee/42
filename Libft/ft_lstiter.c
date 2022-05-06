/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:56:19 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 19:06:33 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

/*#include <stdio.h>
#include <stdlib.h>
void	delet(void *address)
{
	int a = 1;
	*((int *)address) = a;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_list *lst;
	t_list *lst2;
	t_list *first;
	int a = 0;
	int b = 0;

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
	ft_lstiter(lst, &delet);
	first = lst;
	while (first)
	{
		printf("%d -> ", *((int *)(first -> content)));
		first = first -> next;
	}
	printf("NULL\n");
}*/
