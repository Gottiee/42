/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:04:41 by eedy              #+#    #+#             */
/*   Updated: 2022/04/26 14:10:31 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	argv [1][0] = ft_tolower(argv[1][0]);
	//int c = 'G';
	//c = ft_toupper(c);
	//printf("la lettre est %c\n", c);
	printf("la lettre est %c\n", argv[1][0]);
}*/
