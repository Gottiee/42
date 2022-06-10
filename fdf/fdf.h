/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:41:18 by eedy              #+#    #+#             */
/*   Updated: 2022/06/10 18:11:44 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdarg.h>

# include "libft.a/ft_printf.h"
# include "libft.a/libft/libft.h"
# include "libft.a/libft/get_next_line.h"

# define WINDOW_H 1080
# define WINDOW_W 1920
# define IMG_H 4000
# define IMG_W 4000
# define ARGC_PRB 1
# define FD_PRB 2
# define MAP_PARSING_PRB 3
# define MAP_MALLOC_X_PRB 4
# define MLX_PRB 5
# define FREE_MAP 6

typedef struct	s_img
{
	void	*i;
	void	*a;
	int		b;
	int		l;
	int		e;
}				t_img;

typedef struct	s_map
{
	int	color;
	int	z;
}				t_map;

typedef struct	s_bre
{
	int	ex;
	int	ey;
	int	dx;
	int	dy;
	int	dx2;
	int	dy2;
	int	i;
	int	xincr;
	int	yincr;
}				t_bre;

typedef struct	s_square
{
	int	x1;
	int	y1;
	int	px_square;
	int x2;
	int	y2;
}				t_square;

typedef struct	s_data
{
	void 	*mlx_ptr;	
	void	*win_ptr;
	t_img	i;
	int		cur_img;
	t_map	***map;
	int 	zoom;
	int		x;
	int		y;
}				t_data;

/*          --- Fonction qui gere le parsing de MAP ---     */

/*Fichier: map_parsing_two.c*/
void	put_data_struct(t_map *info_map, char *str, int x);
void	struc_fill(t_map *info_map, int nbr, char *str, int i);
int		deci_from_hexa(const char *hexa_str, char *hexa);
int		search_index(const char *hexa_str, char hexa);
int		check_file(char *file_name);

/*Fichier: map_parsing.c*/

t_map	***map_parsing(char *file_name);
void	map_parsing_two(int fd, t_map ***map, char *str, char *file_name);
void	malloc_map_x(t_map ***map, int x_count, char *file_name, int line);
void	malloc_struct(t_map ***map, char *file_name, int x_count);
int		count_x(char *str);

/*          --- Fonction qui gere les erreurs ---     */

/*Fichier: error.c*/
void    error_center(int error, ...);
void    error_no_free(int error);
void    error_free_map_y(va_list ptr);
void    error_free_map_xy(va_list ptr);
void	error_free_map(va_list ptr);

/*          --- Fonction principals ---     */

/*Fichier: main.c*/
int main(int argc, char **argv);

/*          --- Fonction qui gere les calculs des points ---     */

/*Fichier: algo.c*/
int		pixel_square(t_map ***map);
void	algo_bresenham_1(t_img *img, t_square *square, int color, t_bre *bre);
void	algo_bresenham_2(t_img *img, t_square *square, int color, t_bre *bre);
int 	find_w(int img_w, int window_w, t_data *data);
int		find_h(int img_h, int window_h, t_data *data);

/*Fichier: algo2.c*/
int pixel_square2(t_map ***map, int *y, int *x, int *x_count);

/*          --- Fonction qui gere la lib Mlx ---     */

/*Fichier: mlx_fonction.c*/
void	img_pix_put(t_img *img, int x, int y, int color);
int		render(t_data *data);
void	render_line(t_img *img, t_square *square, int color);
void	mlx_center(t_map ***map);
void	quaddrille(t_img *img, int color, int pixel);
void	render_background(t_img *img, int color);

/*Fichier: handle.c*/
int		handle_destroy(t_data *data);
int		handle_keypress(int keysym, t_data *data);
void    keypress_manage(int keysym, t_data *data);
#endif
