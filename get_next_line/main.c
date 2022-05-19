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
	char *filename = "41_with_nl";

	fd = open(filename, O_RDONLY);
	//printf("la seconde chaine lu est : %s", str = get_next_line(fd));
	//free(str);
	while(1)
	{
		str = get_next_line(fd);
		if(!str)
		{
			free(str);
			break;
		}
		printf("%s", str);
		free(str);

	}
	close(fd);
}
