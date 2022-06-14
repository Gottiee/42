/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:11:12 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 18:07:11 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char)c;
	i = 0;
	if (c == 0)
		return ((char *)&s[ft_strlen((char *)s)]);
	while (s[i])
	{
		if (ch == s[i])
			return ((char *)&s[i]);
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
	printf("la lettre a ete trouve a partir de ;%s\n", ft_strchr("d'accord", 'b'));
}*/
