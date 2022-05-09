/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:54:44 by eedy              #+#    #+#             */
/*   Updated: 2022/05/08 14:10:00 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (n)
	{
		if (str[i] == (char)c)
			return (str + i);
		i ++;
		n --;
	}
	return (NULL);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char s[] = {0, 1, 2, 3, 4, 5};
	printf("la lettre trouvee;%s\n", (char *)ft_memchr(s, 6, 6));
	if (ft_memchr(s, 6, 6) == NULL)
		printf("OK\n");
	else
		printf("KO\n");
}*/
