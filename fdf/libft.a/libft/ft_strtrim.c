/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:21:08 by eedy              #+#    #+#             */
/*   Updated: 2022/05/10 17:51:28 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_str(char const *s1, char *str, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		start ++;
		i ++;
	}
}

int	verif(char c, const char *set, int set_len)
{
	int	i;

	i = 0;
	while (i < set_len)
	{
		if (set[i] == c)
			return (0);
		i ++;
	}
	return (1);
}

void	malloc_str(char	const *s1, char const *set, int *start, int *end)
{
	int	i;
	int	s_len;
	int	set_len;

	s_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	i = 0;
	while (i < s_len && !verif(s1[i], set, set_len))
		i ++;
	*start = i;
	i = s_len;
	while (i > 0 && !verif(s1[i - 1], set, set_len))
		i --;
	*end = i;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	malloc_str(s1, set, &start, &end);
	if (start == (int)ft_strlen(s1))
	{
		str = (char *)malloc(sizeof(char) * 1);
		*str = '\0';
	}
	else
	{
		str = malloc(sizeof(char) * (end - start + 1));
		str[end - start] = '\0';
		print_str(s1, str, start, end);
	}
	return (str);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str;
	str = ft_strtrim(" lorem ipsum dolor sit amet", "l ");
	printf("%s\n", str);
}*/
