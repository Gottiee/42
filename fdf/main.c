/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:33:50 by eedy              #+#    #+#             */
/*   Updated: 2022/06/01 13:08:01 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

#define W_H 1080
#define W_W 1920

typedef struct	s_img
{
	void	*mlx_img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_data
{
	void 	*mlx_ptr;	
	void	*win_ptr;
	t_img	img;
	int		cur_img;
}				t_data;

int	color_gen(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp/8));
	*(int *)pixel = color;
}

void	render_line(t_img *img, int color)
{
	int i;

	i = 0;
	while (i < W_W)
		img_pix_put(img, i++ , 100, color);
}

void	render_background(t_img *img, int color)
{
	int	j;
	int	i;

	j = 0;
	while (j < W_H)
	{
		i = 0;
		while (i < W_W)
			img_pix_put(img, i++, j, color);
		j ++;
	}
}


int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, color_gen(255, 255, 255));
	render_line(&data->img, color_gen(0, 0, 255));

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return(0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, W_W, W_W, "Please");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (0);
	}

	//set up image and print int it
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, W_W, W_H);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);

	//set up hooks
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	//quit the window and free everythink

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
