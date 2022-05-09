/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:15:14 by eedy              #+#    #+#             */
/*   Updated: 2022/05/08 15:04:23 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if (!dst || !src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	i = 0;
	if (size == 0)
		return (src_len);
	if (size < dst_len)
		src_len += size;
	else
		src_len += dst_len;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i ++;
	}
	dst[dst_len + i] = '\0';
	return (src_len);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char dest[30];
	memset(dest, 0, 30);
	char *src = (char *)"AAAAAAAAA";
	dest[0] = 'B';
		if (ft_strlcat(dest, src, 6) == 13 && !strcmp(dest, "BBBBA"))
		printf("OK\n");
	else
		printf("KO\n");
}*/
