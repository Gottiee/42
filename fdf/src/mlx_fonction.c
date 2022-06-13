/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:37:59 by eedy              #+#    #+#             */
/*   Updated: 2022/06/13 12:24:18 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->a + (y * img->l + x * (img->b / 8));
	*(int *)pixel = color;
}

void	render_background(t_img *img, int color)
{
	int	j;
	int	i;

	j = 0;
	while (j < IMG_H)
	{
		i = 0;
		while (i < IMG_W)
			img_pix_put(img, i++, j, color);
		j ++;
	}
}

void	render_line(t_img *img, t_s *square, int color)
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

void	mlx_center(t_map ***map)
{
	t_data	data;

	data.zoom = 0;
	data.x = 0;
	data.y = 0;
	data.map = map;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		error_center(MLX_PRB, map);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_W, WINDOW_H, "FDF Eedy");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		error_center(MLX_PRB, map);
	}
	data.i.i = mlx_new_image(data.mlx_ptr, IMG_W, IMG_H);
	data.i.a = mlx_get_data_addr(data.i.i, &data.i.b, &data.i.l, &data.i.e);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 17, StructureNotifyMask, &handle_destroy, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.i.i);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
