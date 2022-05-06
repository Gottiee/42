/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:15:36 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 19:24:16 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	if (!dst || !src)
		return (NULL);
	dest = (char *)dst;
	source = (char *)src;
	if (source < dest)
		ft_memcpy(dest, source, len);
	else
	{
		dest = (char *)dst + (len - 1);
		source = (char *)src + (len - 1);
		while (len --)
			dest[len] = source[len];
	}
	return (dst);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	char dst[5] = "test";
	char src [6] = "okjev";
	ft_memmove(dst, src, 7);
	printf("%s", dst);
	printf("\n");
}*/
