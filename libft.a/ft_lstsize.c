/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:45:45 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 19:29:06 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lst_size;

	if (!lst)
		return (0);
	lst_size = 0;
	while (lst)
	{
		lst = lst -> next;
		lst_size ++;
	}
	return (lst_size);
}
