/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:47:27 by eedy              #+#    #+#             */
/*   Updated: 2022/06/03 13:06:58 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	count_x(char *str)
{
	int	i;
	int	x_count;
	int	str_len;

	i = 0;
	x_count = 0;
	str_len = ft_strlen(str);
	while (i < str_len)
	{
		while (str[i] != ' ' && str[i])
			i ++;
		if (str[i] == ' ')	
			x_count ++;
		i ++;
	}
	return (x_count + 1);
}

void	malloc_struct()

void	malloc_map_x(char ***map, int x_count)
{
	int i;

	i = 0;
	while (map[i])
	{
		map[i] = (char **)malloc(sizeof(char *) * (x_count + 1));
		i ++;
		map[i] = NULL;
		if (!map[i -1])
			error_center(MAP_MALLOC_X_PRB, map, i - 1);
	}
	malloc_struct(map, x_count);
}

void	map_parsing_two(int fd, char ***map, char *str)
{
	int	x_count;
	int	previous_x_count;
	int	line;

	previous_x_count = 0;
	while (line ++)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		x_count = count_x(str);
		if (previous_x_count == 0)
		{
			previous_x_count = x_count;
			line = 1;
		}
		if (x_count != previous_x_count)
		{
			free(str);
			error_center(MAP_PARSING_PRB, map, line);
		}
		free(str);
	}
	close(fd);
	malloc_map_x(map, x_count);
}

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
	while (1)	
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		line_count ++;
	}
	map = (char ***)malloc(sizeof(char **) * (line_count + 1));
	if (!map)
		exit(0);
	map[line_count] = NULL;
	close(fd);
	fd = open(file_name, O_RDONLY);
	map_parsing_two(fd, map, str);
}
