/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:24:04 by eedy              #+#    #+#             */
/*   Updated: 2022/06/08 11:25:54 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	pixel_square(t_map ***map, t_square *square)
{
	int	x;
	int	y;
	int	square_size;

	square->y_per_two = 2;
	y = 0;
	x = 0;
	while (map[y][x])
		x ++;
	while (map[y])
		y ++;
	if (x >= y)
	{
		square_size = ((WINDOW_H / 2 / (x - 1)) / 2);
		while (square_size * x > WINDOW_H || square_size * x > WINDOW_W)
			square_size /= 2;
	}
	if (y > x)
	{
		square_size = ((WINDOW_W / 2 / (y - 1)) / 2);
		while (square_size * y > WINDOW_H || square_size * y > WINDOW_W)
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
