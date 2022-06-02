/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:47:27 by eedy              #+#    #+#             */
/*   Updated: 2022/06/02 14:54:25 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	map_parsing(char *file_name)
{
	int		fd;
	//char	***map;
	int		line_count;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_center(FD_PRB);
	line_count = 0;
	while (get_next_line(fd))	
		line_count ++;
	printf("%d\n", line_count);
}
