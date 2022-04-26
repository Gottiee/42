/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:56:55 by eedy              #+#    #+#             */
/*   Updated: 2022/04/26 15:16:56 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;	

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
