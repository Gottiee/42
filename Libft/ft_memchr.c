/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:54:44 by eedy              #+#    #+#             */
/*   Updated: 2022/04/26 16:10:54 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	ch;

	str = (char *)s;
	ch = (char)c;
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == ch)
			return ((void *)&s[i]);
		i ++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("la lettre trouvee;%s\n", (char *)ft_memchr("d'accord", 'c', 8));
}*/
