/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:24:04 by eedy              #+#    #+#             */
/*   Updated: 2022/06/08 13:06:29 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	pixel_square(t_map ***map)
{
	int	x;
	int	y;
	int	square_size;
	int	x_count;
	int	bigest_z;

	y = 0;
	x = 0;
	bigest_z = 0;
	while (map[y][x])
		x ++;
	x_count = x;
	while (map[y])
	{
		x = 0;	
		while (map[y][x])
		{
			if (map[y][x]->z - y > bigest_z)
				bigest_z = map[y][x]->z - y;
			x ++;
		}
		y ++;
	}
	if (x >= y)
	{
		square_size = ((WINDOW_H / 2 / (x_count - 1)) / 2);
		while (square_size * x_count > WINDOW_H / 4 || square_size * x_count > WINDOW_W || bigest_z *square_size > WINDOW_H / 4)
			square_size /= 2;
	}
	if (y > x)
	{
		square_size = ((WINDOW_W / 2 / (y - 1)) / 2);
		while (square_size * y > WINDOW_H / 4 || square_size * y > WINDOW_W || bigest_z *square_size > WINDOW_H / 4 )
			square_size /= 2;
	}
	return (square_size);
}

void	algo_bresenham_2(t_img *img, t_square *square, int color, t_bre *bre)
{
	while (bre->i <= bre->dx2)
	{
		img_pix_put(img, square->x1, square->y1, color);
		bre->i ++;
		square->y1 += bre->yincr;
		bre->ey -= bre->dx;
		if (bre->ey < 0)
		{
			square->x1 += bre->xincr;
			bre->ey =+ bre->dy;
		}
	}
}

void	algo_bresenham_1(t_img *img, t_square *square, int color, t_bre *bre)
{
	while (bre->i <= bre->dx2)
	{
		img_pix_put(img, square->x1, square->y1, color);
		bre->i ++;
		square->x1 += bre->xincr;
		bre->ex -= bre->dy;
		if (bre->ex < 0)
		{
			square->y1 += bre->yincr;
			bre->ex += bre->dx;
		}
	}
}
