/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:38:43 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 19:23:19 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	if (!b)
		return (NULL);
	i = 0;
	tmp = (unsigned char *)b;
	while (i < len)
	{
		tmp[i] = c;
		i ++;
	}
	return (b);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int i = 0;
	char *str = (char *)malloc(sizeof(char) * 10);
	str[0] = 'a';
	str[1] = 'b';

	str = ft_memset(str, 97, 6);
	
	while (str[i])
	{
		printf("%c", str[i]);
		i ++;
	}
	printf("\n");
	
	i = 0;
	char *s = (char *)malloc(sizeof(char) * 10);
	s[0] = 'a';
	s[1] = 'b';

	s = memset(s, 97, 6);
	
	while (s[i])
	{
		printf("%c", s[i]);
		i ++;
	}	
	printf("\n");
}*/
