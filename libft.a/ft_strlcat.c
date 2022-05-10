/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:15:14 by eedy              #+#    #+#             */
/*   Updated: 2022/05/10 15:18:06 by eedy             ###   ########.fr       */
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

/*void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

int	main(int argc, char **argv)
{
		char	*dest;
		if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
		memset(dest, 'r', 15);
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
		write(1, "\n", 1);
		write(1, dest, 15);
}*/
