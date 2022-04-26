/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:15:36 by eedy              #+#    #+#             */
/*   Updated: 2022/04/26 14:00:29 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

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
