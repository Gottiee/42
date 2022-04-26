/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:11:43 by eedy              #+#    #+#             */
/*   Updated: 2022/04/26 16:46:00 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str;	
	char	*str2;

	i = 0;
	str = (char *)s1;
	str2 = (char *)s2;
	while (str[i] && str2[i] && i < n)
	{
		if (str[i] != str2[i])
			return (str[i] - str2[i]);
		i ++;
	}
	return (0);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//printf("%d\n", ft_strncmp(argv[1], argv[2], argv[3][0]));
	printf("%d\n", ft_memcmp("helloa", "hellob", 6));
}*/
