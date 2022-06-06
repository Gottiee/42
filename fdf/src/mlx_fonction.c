/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:37:59 by eedy              #+#    #+#             */
/*   Updated: 2022/06/06 17:39:33 by eedy             ###   ########.fr       */
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
		while (data->map[y][x + 1])
		{
			square.x1 = x * px_square * 2 + (WINDOW_W / 2) - (y * (px_square * 2));	
			square.y1 = y * px_square + x * px_square;
			square.x2 = square.x1 + square.px_square * 2;
			square.y2 = square.y1 + square.px_square;
			render_line(&data->img, &square, map[y][x]->color);
			square.x1 = (WINDOW_W / 2) - x * px_square * 2 + (y * (px_square * 2));
			square.x2 = square.x1 - square.px_square * 2;
			render_line(&data->img, &square, map[y][x]->color);
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
	bre.ey = square->y2 - square->y1;
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
	if (bre.dx2 > bre.dy2)
		algo_bresenham_1(img, square, color, &bre);
	else
		algo_bresenham_2(img, square, color, &bre);
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
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_W, WINDOW_H);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);

	//set up hooks
	mlx_hook(data.win_ptr, 17, StructureNotifyMask, &handle_destroy, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	//quit the window and free everythink

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
