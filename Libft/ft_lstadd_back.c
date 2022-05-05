/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:14:38 by eedy              #+#    #+#             */
/*   Updated: 2022/05/04 16:33:45 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while (*lst)
		*lst = lst -> next;
	new -> next = NULL;
	*lst = *new;
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_list *first_lst;
	first_lst = malloc(sizeof(t_list));
	t_list **ptr_first;
	*ptr_first = first_lst;
	t_list *new;
	new -> (int)content = 3;
	first_lst -> (int)content = 1;
	ft_lstadd_back(ptr_first, new);
	while (*ptr_first)
	{
		printf("%d, ", first_lst -> (int)content);
		*ptr_first = ptr_first -> next;
	}
	printf("\n");
}
