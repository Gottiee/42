/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:42:25 by eedy              #+#    #+#             */
/*   Updated: 2022/06/10 18:12:11 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
	keypress_manage(keysym, data);
	if (keysym == 119)
		data->zoom += 1;
	else if (keysym == 115)
		data->zoom -= 1;
	else if (keysym == XK_Up)
	{
		data->y -= 15;
	}
	else if (keysym == XK_Left)
		data->x -= 15;
	else if (keysym == XK_Down)
	{
		data->y += 15;
	}
	else if (keysym == XK_Right)
		data->x += 15;
	return (0);
}

int	handle_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->i.i);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	error_center(FREE_MAP, data->map);
	exit(0);
}

void	keypress_manage(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		mlx_destroy_image(data->mlx_ptr, data->i.i);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		error_center(FREE_MAP, data->map);
		exit(0);
	}
}
