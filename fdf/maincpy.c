#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

#define W_H 1080
#define W_W 1920

typedef struct	s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_data
{
	void 	*mlx;	
	void	*mlx_win;
	t_img	img;
}				t_data;

int	color(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp/8));
	*(int *)pixel = color;
}

int	render(t_data *data)
{
	int i;
	int	j;

	j = 0;
	if (data->mlx_win == NULL)
		return (0);
	while (j < W_H)
	{
		i = 0;
		while (i < W_W)
			img_pix_put(&data->img, i++, j, color(125, 125, 000));
		j ++;
	}
	i = 0;
	while (i < W_W)
	{
		img_pix_put(&data->img, i , 100, color(255, 0, 0));
		i ++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "line");
	data.img.img = mlx_new_image(data.mlx, W_W, W_H);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
}
