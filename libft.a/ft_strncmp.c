/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:18:10 by eedy              #+#    #+#             */
/*   Updated: 2022/05/10 17:56:30 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;	
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!str1 || !str2)
		return (0);
	i = 0;
	while (n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i ++;
		n --;
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
	printf("%d\n", strncmp("test\200", "test\0", 6));
}*/
