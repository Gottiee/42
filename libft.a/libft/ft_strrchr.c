/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:56:55 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 18:28:29 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;	

	if (!s)
		return (NULL);
	ch = (char)c;
	i = ft_strlen((char *)s);
	if (c == 0)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (ch == s[i])
			return ((char *)&s[i]);
		i --;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("la lettre trouve;%s\n", ft_strrchr("d'accorb", '\0'));
}*/
