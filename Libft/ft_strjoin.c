/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:00:32 by eedy              #+#    #+#             */
/*   Updated: 2022/04/27 16:19:21 by eedy             ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;
	size_t	s1_len;

	s1_len = ft_strlen((char *)s1);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (s1_len + ft_strlen((char *)s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i ++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i ++;
		j ++;
	}
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str; 
	str = ft_strjoin("lets", "go");
	printf("%s\n", str);
}*/
