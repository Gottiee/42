/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:37:59 by eedy              #+#    #+#             */
/*   Updated: 2022/06/09 16:10:10 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp/8));
	*(int *)pixel = color;
}

int	render(t_data *data)
{
	int			y;
	int			x;
	t_square	square;

	square.px_square = pixel_square(data->map);
	y = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			square.x1 = WINDOW_W / 2 + (x * square.px_square * 2) - (y * square.px_square * 2);
			square.y1 = WINDOW_H / 4 + (y * square.px_square + x * square.px_square) - (data->map[y][x]->z * square.px_square);
			if (data->map[y][x + 1])
			{
				square.x2 = square.x1 + square.px_square * 2;
				square.y2 = square.y1 + square.px_square + (data->map[y][x]->z * square.px_square) - (data->map[y][x + 1]->z * square.px_square);
				render_line(&data->img, &square, data->map[y][x]->color);
			}
			if (data->map[y + 1])
			{
				square.x1 = WINDOW_W / 2 + (x * square.px_square * 2) - (y * square.px_square * 2);
				square.y1 = WINDOW_H / 4 + (y * square.px_square + x * square.px_square) - (data->map[y][x]->z * square.px_square);
				square.x2 = square.x1 - square.px_square * 2;
				square.y2 = square.y1 + square.px_square + (data->map[y][x]->z * square.px_square) - (data->map[y + 1][x]->z * square.px_square);
				render_line(&data->img, &square, data->map[y][x]->color);
			}
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

void	render_line(t_img *img, t_square *square, int color)
{
	t_bre	bre;		

	bre.ex = square->x2 - square->x1;
	if (bre.ex < 0)
		bre.ex *= -1;
	bre.ey = square->y2 - square->y1;
	if (bre.ey < 0)
		bre.ey *= -1;
	bre.dx = 2 * bre.ex;
	bre.dy = 2 * bre.ey;
	bre.dx2 = bre.ex;
	bre.dy2 = bre.ey;
	bre.i = 0;
	bre.xincr = 1;
	bre.yincr = 1;
	if (square->x1 > square-> x2)
		bre.xincr = -1;
	if (square->y1 > square-> y2)
		bre.yincr = -1;
	if (bre.dx2 >= bre.dy2)
		algo_bresenham_1(img, square, color, &bre);
	if (bre.dx2 < bre.dy2)	
		algo_bresenham_2(img, square, color, &bre);
}

void	quaddrille(t_img *img, int color, int pixel)
{
	int i = 0;
	int	x;
	while (i * pixel < WINDOW_H)
	{
		x = 0;
		while (x < WINDOW_W)
			img_pix_put(img, x++, pixel * i , color);
		i ++;
	}
	i = 0;
	while (i * pixel < WINDOW_W)
	{
		x = 0;	
		while (x < WINDOW_H)
			img_pix_put(img, pixel * i, x++, color);
		i ++;
	}
}

void	mlx_center(t_map ***map)
{
	t_data	data;

	data.map = map;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		error_center(MLX_PRB, map);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_W, WINDOW_H, "Please");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		error_center(MLX_PRB, map);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, IMG_W, IMG_H);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 17, StructureNotifyMask, &handle_destroy, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
