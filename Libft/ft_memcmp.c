/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:11:43 by eedy              #+#    #+#             */
/*   Updated: 2022/05/08 13:52:36 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;	
	unsigned char	*str2;

	if (!s1 || !s2)
		return (0);
	i = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n)
	{
		if (str[i] != str2[i])
			return (str[i] - str2[i]);
		i ++;
		n --;
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//printf("%d\n", ft_strncmp(argv[1], argv[2], argv[3][0]));
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	printf("%d\n", ft_memcmp(s, s2, 1));
	if (ft_memcmp(s, s2, 1) > 0)
		printf("OK\n");
	else
		printf("KO\n");
}*/
