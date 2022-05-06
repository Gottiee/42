/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:27:12 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 19:28:18 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;

	if (!dst || !src)
		return (0);
	i = 0;
	lensrc = ft_strlen((char *)src);
	if (dstsize == 0)
		return (lensrc);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i ++;
	}
	if (lensrc < dstsize)
	dst[lensrc] = '\0';
	return (lensrc);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	char dst[] = "aaaa";
	char src[] = "testo";
	strlcpy(dst, src, 6);
	printf("%s", dst);
	printf("\n");
}*/
