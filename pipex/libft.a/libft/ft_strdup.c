/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:06:26 by eedy              #+#    #+#             */
/*   Updated: 2022/05/09 11:10:05 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		s1_len;
	int		i;

	i = 0;
	s1_len = ft_strlen((char *)s1);
	str = (char *)malloc(sizeof(char) * s1_len + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i ++;
	}
	str [i] = '\0';
	return (str);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	char *str;
	str = ft_strdup((char *) "coucou");
	printf("%s\n", str);
	printf("%d <- mcheck fonction return\n", mcheck(str, strlen("coucou") + 1));
	free(str);
}*/
