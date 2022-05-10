/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:02:17 by eedy              #+#    #+#             */
/*   Updated: 2022/05/09 18:12:26 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif_s(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (0);
		i ++;
	}
	return (1);
}

static void	print_str(char **str, const char *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	word;

	word = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] != c && s[i])
		{
			str[j][k] = s[i];
			word ++;
			k ++;
			i ++;
		}
		if (word != 0 && s[i + 1] != c && s[i + 1] != '\0')
			j ++;
		i ++;
	}
}

static void	malloc_line(char **str, const char *s, char c)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while (s[i] != c && s[i])
		{
			count ++;
			i ++;
		}
		if (count != 0)
		{
			str[j] = (char *)malloc(sizeof(char) * (count + 1));
			if (!str[j])
				return ;
			str[j][count] = '\0';
			j ++;
		}
		if (s[i])
			i ++;
	}
	print_str(str, s, c);
}

static int	str_line(const char *s, char c)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
			word ++;
		if (s[i] == c && word != 0 && s[i + 1] != c && s[i + 1] != '\0')
			count ++;
		i ++;
	}
	return (count + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	str_len;

	if (s[0] == '\0' || verif_s(s, c))
		return (NULL);
	str_len = str_line(s, c);
	str = (char **)malloc(sizeof(char *) * (str_len + 1));
	if (!str)
		return (NULL);
	str[str_len] = '\0';
	malloc_line(str, s, c);
	return (str);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int i = 0;
	(void)argc;
	char **str;
	str = ft_split(argv[1], argv[2][0]);
	while (str[i])
	{
		printf("%s\n", str[i]);
		i ++;
	}
}*/
