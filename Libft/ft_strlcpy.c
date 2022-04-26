/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:27:12 by eedy              #+#    #+#             */
/*   Updated: 2022/04/26 13:59:59 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;

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
