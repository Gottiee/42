/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:09:24 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 18:26:03 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*new_s;
	int		s_len;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_len = ft_strlen((char *)s);
	new_s = malloc(sizeof(char) * s_len + 1);
	if (!new_s)
		return (NULL);
	new_s[s_len] = '\0';
	while (s[i])
	{
		new_s[i] = (f)(i, s[i]);
		i ++;
	}
	return (new_s);
}
