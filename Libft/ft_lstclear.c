/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:38:00 by eedy              #+#    #+#             */
/*   Updated: 2022/05/05 17:48:38 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (del)(void *))
{
	t_list *tmp;
	while(*lst -> next)
	{
		del(*lst -> content);
		tmp = *lst;
		*lst = *lst -> next;
		free(lst);
	}
}
