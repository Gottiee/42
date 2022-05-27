/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:47:57 by eedy              #+#    #+#             */
/*   Updated: 2022/05/10 17:54:12 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack || !needle)
		return (NULL);
	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && haystack[i + j] == needle[j]
			&& len != 0 && i + j < len)
			j ++;
		if (!needle[j] || j == ft_strlen(needle))
			return ((char *)&haystack[i]);
		i ++;
	}
	return (NULL);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char *empty = (char *)"";

	if (ft_strnstr(haystack, "abcd", 9) == haystack + 5)
		printf("OK\n");
	else
		printf("KO\n");
}*/
