/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:30:55 by eedy              #+#    #+#             */
/*   Updated: 2022/06/10 17:54:06 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	pixel_square2(t_map ***map, int *y, int *x, int *x_count)
{
	int	bigest_z;

	bigest_z = 0;
	*y = 0;
	*x = 0;
	while (map[*y][*x])
		(*x)++;
	*x_count = *x;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x]->z - *y > bigest_z)
				bigest_z = map[*y][*x]->z - *y;
			(*x)++;
		}
		(*y)++;
	}
	return (bigest_z);
}
