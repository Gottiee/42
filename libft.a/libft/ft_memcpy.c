/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:58:34 by eedy              #+#    #+#             */
/*   Updated: 2022/05/11 15:42:19 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	source = (char *)src;
	dest = (char *)dst;
	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			dest[i] = source[i];
			i ++;
		}
	}
	return (dst);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *src = NULL;
	char dst[] = "test";
	char dst2[] = "test";
	ft_memcpy(dst, src, 0);
	memcpy(dst2, src, 0);
	printf("ma fonction :%s\n", dst);
	printf("leur fonction :%s\n", dst2);
}*/
