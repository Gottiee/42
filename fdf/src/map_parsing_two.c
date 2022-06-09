/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:35:28 by eedy              #+#    #+#             */
/*   Updated: 2022/06/09 15:45:47 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	search_index(const char *hexa_str, char hexa)
{
	int	i;

	i = 0;
	while (hexa != hexa_str[i])
		i ++;
	return (i);
}

int	deci_from_hexa(const char *hexa_str, char *hexa)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (hexa[i])
	{
		nbr = nbr * 16 + search_index(hexa_str, hexa[i]);
		i ++;
	}
	return (nbr);
}

void	struc_fill(t_map *info_map, int nbr, char *str, int i)
{
	char		hexa[7];
	int			j;
	int			hexa_nbr;

	j = 0;
	info_map->z = nbr;
	if (str[i] != ',')
	{
		info_map->color = 16777215;
		return ;
	}
	i += 3;
	while (str[i] != ' ' && str[i])	
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		hexa[j] = str[i];
		j ++;
		i ++;
	}
	hexa[j] = '\0';
	hexa_nbr = deci_from_hexa("012345789ABCDEF", hexa);
	info_map->color = hexa_nbr;
}

void	put_data_struct(t_map *info_map, char *str, int x)
{
	int	i;
	int	space_count;
	int	nbr;
	int	neg;

	i = 0;
	nbr = 0;
	space_count = 0;
	neg = 1;
	while (x != space_count)
	{
		if (str[i] == ' ')
			space_count	++;
		i++;	
	}
	neg -= 2 * (str[i] == '-');
	i += (str[i] == '-');
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i ++;
	}
	nbr *= neg;
	struc_fill(info_map, nbr, str, i);
}

int	check_file(char *file_name)
{
	int		fd;
	int		line_count;
	char	*str;

	line_count = 0;
	fd = open(file_name, O_RDONLY);
	while (1)	
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		line_count ++;
	}
	if (line_count > 0)
		return (0);
	return (1);
}
