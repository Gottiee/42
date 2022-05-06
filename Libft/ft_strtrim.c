/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:21:08 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 18:29:41 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_verif(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i ++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		if (set_verif(s1[i], set))
		{
			str[j] = s1[i];
			j ++;
		}
		i ++;
	}
	return (str);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str;
	str = ft_strtrim("okletsgo", "okh");
	printf("%s\n", str);
}*/
