/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:54:44 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 19:12:39 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	ch;

	if (!s)
		return (NULL);
	str = (char *)s;
	ch = (char)c;
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == ch)
			return (str + i);
		i ++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("la lettre trouvee;%s\n", (char *)ft_memchr("d'accord", 'c', 8));
}*/
