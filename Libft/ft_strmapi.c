/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:09:24 by eedy              #+#    #+#             */
/*   Updated: 2022/05/04 01:11:26 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	while (str[i])
		i ++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*new_s;
	int		s_leng;
	int		i;

	i = 0;
	len = ft_strlen((char *)s);
	new_s = malloc(sizeof(char) * len + 1);
	if (!new_s)
		return (NULL);
	s_new[len] = '\0';
	while (s[i])
	{
		new_s[i] = (f)(i, s[i]);
		i ++;
	}
	return (new_s);
}
