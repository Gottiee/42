/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:30:18 by eedy              #+#    #+#             */
/*   Updated: 2022/05/09 12:18:58 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cpy_str(char const *s, unsigned int start, size_t len, char *str)
{
	size_t	i;	
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (start > s_len)
		return ;
	while (s[i] && i < len)
	{
		str[i] = s[start];
		start ++;
		i ++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	else if ((s_len + 1 - start) <= len)
	{
		str = (char *)malloc(sizeof(char) * s_len + 1 - start);
		str[s_len - start] = '\0';
	}
	else
	{
		str = (char *)malloc(sizeof(char) * len + 1);
		str[len] = '\0';
	}
	if (!str)
		return (NULL);
	cpy_str(s, start, len, str)	;
	return (str);
}

/*int    main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    char *str;
    char * s = strdup("1");
    str = ft_substr(s, 42, 42000000);
    printf("%s\n", str);
	free(str);
	free(s);
}*/
