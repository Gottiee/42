/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:47:27 by eedy              #+#    #+#             */
/*   Updated: 2022/06/10 17:56:22 by eedy             ###   ########.fr       */
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

void	malloc_struct(t_map ***map, char *file_name, int x_count)
{
	int		y;
	int		x;
	int		fd;
	char	*str;

	y = 0;
	fd = open(file_name, O_RDONLY);
	while (map[y])
	{
		x = 0;
		str = get_next_line(fd);
		while (x < x_count)
		{
			map[y][x] = malloc(sizeof(t_map));
			put_data_struct(map[y][x], str, x);
			x ++;
		}
		y ++;
		free(str);
	}
	close(fd);
}

void	malloc_map_x(t_map ***map, int x_count, char *file_name, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		map[i] = malloc(sizeof(t_map *) * (x_count + 1));
		map[i][x_count] = NULL;
		i ++;
		map[i] = NULL;
		if (!map[i -1])
			error_center(MAP_MALLOC_X_PRB, map, i - 1);
	}
	malloc_struct(map, file_name, x_count);
}

void	map_parsing_two(int fd, t_map ***map, char *str, char *file_name)
{
	int	x_count;
	int	previous_x_count;
	int	line;

	line = -1;
	previous_x_count = 0;
	while (line ++)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		x_count = count_x(str);
		line += (previous_x_count == 0);
		if (previous_x_count == 0)
			previous_x_count = x_count;
		if (x_count != previous_x_count)
		{
			free(str);
			error_center(MAP_PARSING_PRB, map, line);
		}
		free(str);
	}
	close(fd);
	malloc_map_x(map, x_count, file_name, line - 1);
}

t_map	***map_parsing(char *file_name)
{
	int		fd;
	t_map	***map;
	int		line_count;
	char	*str;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || check_file(file_name))
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
	map = malloc(sizeof(t_map **) * (line_count + 1));
	if (!map)
		exit(0);
	map[line_count] = NULL;
	close(fd);
	fd = open(file_name, O_RDONLY);
	map_parsing_two(fd, map, str, file_name);
	return (map);
}
