/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:55:31 by eedy              #+#    #+#             */
/*   Updated: 2022/05/18 12:30:32 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *str;

	fd = open("test", O_RDONLY);
	str = get_next_line(fd);
	printf("la chaine lu est : %s", str);
	printf("la seconde chaine lu est : %s", get_next_line(fd));
	printf("la seconde chaine lu est : %s", get_next_line(fd));
	printf("la seconde chaine lu est : %s", get_next_line(fd));
	printf("la seconde chaine lu est : %s", get_next_line(fd));
	printf("la seconde chaine lu est : %s", get_next_line(fd));
	printf("la seconde chaine lu est : %s", get_next_line(fd));
	printf("la seconde chaine lu est : %s", get_next_line(fd));
	printf("la seconde chaine lu est : %s", get_next_line(fd));
}
