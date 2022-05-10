/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:00:01 by eedy              #+#    #+#             */
/*   Updated: 2022/05/10 17:53:14 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	if (count == 0 || size == 0)
		return (NULL);
	str = (void *)malloc(count * size);
	if (!str)
		return (NULL);
	while (i < count * size)
	{
		str[i] = 0;
		i ++;
	}
	return ((void *)str);
}
