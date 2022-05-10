/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:56:14 by eedy              #+#    #+#             */
/*   Updated: 2022/05/10 12:58:44 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	t_list *second;
	t_list *first;
	int a = 0;
	int b = 1;

	second = malloc(sizeof(t_list));
	first = malloc(sizeof(t_list));
	first -> next = second;
	second -> next = NULL;	
	first -> content = (int *)&a;
	second -> content = (int *)&b;
	if (ft_lstlast(first)->content)
		printf("bah ca marche ?");
}*/
