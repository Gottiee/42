/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:00:01 by eedy              #+#    #+#             */
/*   Updated: 2022/05/11 15:43:11 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*str;
	const size_t	m = count * size;

	if (size && m / size != count)
		return (NULL);
	str = malloc(m);
	if (!str)
		return (NULL);
	return (ft_memset(str, 0, m));
}
