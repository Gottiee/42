/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:47:27 by eedy              #+#    #+#             */
/*   Updated: 2022/06/02 15:42:52 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	map_parsing(char *file_name)
{
	int		fd;
	char	***map;
	int		line_count;
	char 	*str;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_center(FD_PRB);
	line_count = 0;
	while (str != NULL)	
	{
		str = get_next_line(fd);
		free(str);
		line_count ++;
	}
	map = (char ***)malloc(sizeof(char **) * (line_count + 1));
	if (!map)
		exit(0);
	map[line_count] = '\0';
	close(fd);
	fd = open(file_name, O_RDONLY);
	while (map)
	{
		map++ = get_next_line(fd);
	}
}
