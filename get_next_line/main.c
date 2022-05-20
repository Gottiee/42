/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:55:31 by eedy              #+#    #+#             */
/*   Updated: 2022/05/20 12:56:36 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int			fd;
	char		*str;
	const char	*filename = "test";

	fd = open(filename, O_RDONLY);
	printf("la seconde chaine lu est : %s", str = get_next_line(fd));
	free(str);
	printf("la seconde chaine lu est : %s", str = get_next_line(fd));
	free(str);
	printf("la seconde chaine lu est : %s", str = get_next_line(fd));
	free(str);
	printf("la seconde chaine lu est : %s", str = get_next_line(fd));
	free(str);
	printf("la seconde chaine lu est : %s", str = get_next_line(fd));
	free(str);
	printf("la seconde chaine lu est : %s", str = get_next_line(fd));
	free(str);
	close(fd);
}
