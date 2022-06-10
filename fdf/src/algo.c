/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:24:04 by eedy              #+#    #+#             */
/*   Updated: 2022/06/10 15:22:54 by eedy             ###   ########.fr       */
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
		while (square_size * y > WINDOW_H / 4 || square_size * y > WINDOW_W || bigest_z *square_size > WINDOW_H / 2 )
			square_size /= 2;
	}
	return (square_size);
}

void	algo_bresenham_2(t_img *img, t_square *square, int color, t_bre *bre)
{
	while (bre->i <= bre->dy2)
	{
		if (square->y1 < IMG_H && square->x1 < IMG_W)
			img_pix_put(img, square->x1, square->y1, color);
		bre->i ++;
		square->y1 += bre->yincr;
		bre->ey -= bre->dx;
		if (bre->ey < 0)
		{
			square->x1 += bre->xincr;
			bre->ey += bre->dy;
		}
	}
}

void	algo_bresenham_1(t_img *img, t_square *square, int color, t_bre *bre)
{
	while (bre->i <= bre->dx2)
	{
		if (square->y1 < IMG_H && square->x1 < IMG_W)
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

int	find_w(int img_w, int window_w, t_data *data)
{
	float	result;
	float	i_w;
	float	w_w;

	i_w = img_w;
	w_w = window_w;
	result = ((i_w / w_w) - 1) * (w_w / 2) * - 1;
	result += data->x;
	return (result);
}

int find_h(int img_h, int window_h, t_data *data)
{
	float	result;
	float	i_h;
	float	w_h;

	i_h = img_h;
	w_h = window_h;
	result = ((i_h / w_h) - 1) * (w_h / 4) * -1;
	result += data->y;
	return (result);
}
