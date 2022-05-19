/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:55:31 by eedy              #+#    #+#             */
/*   Updated: 2022/05/19 15:52:59 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test", O_RDONLY);
	printf("la seconde chaine lu est : %s", str = get_next_line(fd));
	free(str);
	close(fd);
}
