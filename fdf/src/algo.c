/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:24:04 by eedy              #+#    #+#             */
/*   Updated: 2022/06/06 17:44:26 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	pixel_square(t_map ***map)
{
	int	x;
	int	y;
	int	x_count;

	y = 0;
	x_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			x_count ++;
			x ++;
		}
		y ++;
	}
	return (((WINDOW_W / 2) / x_count - 1) / 2);
}

void	algo_bresenham_2(t_img *img, t_square *square, int color, t_bre *bre)
{
	while (bre->i <= bre->dx2)
	{
		img_pix_put(img, square->x1, square->y1, color);
		i ++;
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
		i ++;
		square->x1 += bre->xincr;
		bre->ex -= bre->dy;
		if (bre->ex < 0)
		{
			square->y1 += bre->yincr;
			bre->ex =+ bre->dx;
		}
	}
}
