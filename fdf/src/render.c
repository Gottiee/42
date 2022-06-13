/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:54:42 by eedy              #+#    #+#             */
/*   Updated: 2022/06/13 13:55:11 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	render(t_data *d)
{
	int			y;
	int			x;
	t_s			s;
	t_screen	h;

	render_background(&d->i, 0x451241);
	s.px_s = pixel_square(d->map);
	if (s.px_s + d->zoom > 0)
		s.px_s += d->zoom;
	else
		d->zoom += 1;
	y = 0;
	if (d->win_ptr == NULL)
		return (1);
	while (d->map[y])
	{
		x = 0;
		while (d->map[y][x])
			x += calcul_coordinate(d, &s, &x, &y);
		y ++;
	}
	h.w = find_w(IMG_W, WINDOW_W, d);
	h.h = find_h(IMG_H, WINDOW_H, d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->i.i, h.w, h.h);
	return (0);
}

int	calcul_coordinate(t_data *d, t_s *s, int *x, int *y)
{
	int	tmp;

	s->x1 = IMG_W / 2 + (*x * s->px_s * 2) - (*y * s->px_s * 2);
	tmp = (*y * s->px_s + *x * s->px_s) - (d->map[*y][*x]->z * s->px_s);
	s->y1 = IMG_H / 4 + tmp;
	if (d->map[*y][*x + 1])
	{
		s->x2 = s->x1 + s->px_s * 2;
		tmp = (d->map[*y][*x]->z * s->px_s) - (d->map[*y][*x + 1]->z * s->px_s);
		s->y2 = s->y1 + s->px_s + tmp;
		render_line(&d->i, s, d->map[*y][*x]->color);
	}
	if (d->map[*y + 1])
	{
		s->x1 = IMG_W / 2 + (*x * s->px_s * 2) - (*y * s->px_s * 2);
		tmp = (*y * s->px_s + *x * s->px_s) - (d->map[*y][*x]->z * s->px_s);
		s->y1 = IMG_H / 4 + tmp;
		s->x2 = s->x1 - s->px_s * 2;
		tmp = (d->map[*y][*x]->z * s->px_s) - (d->map[*y + 1][*x]->z * s->px_s);
		s->y2 = s->y1 + s->px_s + tmp;
		render_line(&d->i, s, d->map[*y][*x]->color);
	}
	return (1);
}
