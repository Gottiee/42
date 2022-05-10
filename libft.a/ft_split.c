/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:02:17 by eedy              #+#    #+#             */
/*   Updated: 2022/05/10 18:07:38 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif_s(const char *s, char c, int s_len)
{
	int	i;

	i = 0;
	while (i < s_len)
	{
		if (s[i] != c)
			return (0);
		i ++;
	}
	return (1);
}

static void	print_str(char **str, const char *s, char c, int s_len)
{
	int	i;
	int	j;
	int	k;
	int	word;

	word = 0;
	i = 0;
	j = 0;
	while (i < s_len)
	{
		k = 0;
		while (i < s_len && s[i] != c)
		{
			str[j][k] = s[i];
			word ++;
			k ++;
			i ++;
		}
		if (i < s_len && word != 0 && s[i + 1] != c && s[i + 1] != '\0')
			j ++;
		i ++;
	}
}

static void	malloc_line(char **str, const char *s, char c, int s_len)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	j = 0;
	while (i < s_len)
	{
		count = 0;
		while (i < s_len && s[i] != c)
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
		i ++;
	}
	print_str(str, s, c, s_len);
}

static int	str_line(const char *s, char c, int s_len)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (i < s_len)
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
	int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	str_len = str_line(s, c, s_len);
	if (verif_s(s, c, s_len))
	{
		str = malloc(sizeof(char *) * 1);
		str[0] = NULL;
		return (str);
	}
	else
		str = (char **)malloc(sizeof(char *) * (str_len + 1));
	if (!str)
		return (NULL);
	str[str_len] = NULL;
	malloc_line(str, s, c, s_len);
	return (str);
}

/*int	main(int argc, char **argv)
{
	char * * tab = ft_split("  tripouille  42  ", ' ');
    tab = ft_split("tripouille", 0);
    if (tab[1]==NULL)
      printf("ok");
}*/
