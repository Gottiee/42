/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:30:18 by eedy              #+#    #+#             */
/*   Updated: 2022/05/10 11:11:36 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	int		malloc_s;
	int		i;

	s_len = ft_strlen(s);
	if (start > s_len)
		malloc_s = 1;
	else if ((s_len + 1 - start) <= len)
		malloc_s = s_len + 1 - start;
	else
		malloc_s = len + 1;
	str = (char *)malloc(sizeof(char) * malloc_s);
	if (!str)
		return (NULL);
	i = 0;
	while (i < malloc_s)
	{
		str[i] = '\0';
		i ++;
	}
	if (s + start <= s + s_len)
		ft_strlcpy(str, s + start, malloc_s);
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
    if (!strcmp(str, ""))
      printf("ok");
	free(str);
	free(s);
}*/
