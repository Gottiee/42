/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:21:08 by eedy              #+#    #+#             */
/*   Updated: 2022/05/09 12:58:29 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_set(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	n_set;

	i = 0;
	n_set = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				n_set ++;
			j ++;
		}
		i ++;
	}
	return (n_set);
}

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
	int		n_set;

	if (!s1 || !set)
		return (NULL);
	j = 0;
	i = 0;
	n_set = count_set(s1, set);
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1 - n_set);
	if (!str)
		return (NULL);
	str[ft_strlen(s1) - n_set] = '\0';
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
