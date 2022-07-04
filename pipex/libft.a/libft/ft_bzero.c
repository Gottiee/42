/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:56:04 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 19:15:58 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	if (!s)
		return ;
	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		tmp[i] = 0;
		i ++;
	}
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int i = 0;
	char *str;
	str = (char *)malloc(sizeof(char) * 10);
	str[0] = 'a';
	str[1] = 'b';
	str[6]  = 'g';

	ft_bzero(str, 5);

	while (i < 10)
	{
		printf("%c", str[i]);
		i ++;
	}
}*/
