/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:58:34 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 19:13:14 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	if (!dst || !src)
		return (NULL);
	source = (char *)src;
	dest = (char *)dst;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i ++;
	}
	return (dst);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *src;
	char *dst = (char *)malloc(sizeof(char) * 10);
	src = (char *)malloc(sizeof(char) * 10);
	dst[0] = '6';
	src[0] = 'a';
	src[1] = 'b';
	dst = ft_memcpy(dst, src, 2);

	int i = 0;
	while (i < 10)
	{
		printf("%c", dst[i]);
		i ++;
	}
	printf("\n");
}*/
