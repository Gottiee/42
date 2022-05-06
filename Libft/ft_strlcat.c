/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:15:14 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 19:28:36 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	if (!dst || !src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	i = 0;
	j = ft_strlen(dst);
	if (size <= dst_len)
		return (dst_len + src_len);
	while (src[i] && size - 1 > j)
	{
		dst[j] = src[i];
		i ++;
		j ++;
	}
	dst[dst_len + src_len] = '\0';
	return (dst_len + src_len);
}

/*#include <string.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char source[10] = "testost";
	char dst[10] = "ok";
	ft_strlcat(dst, source, 10);
	printf("%s\n", dst);
}*/
