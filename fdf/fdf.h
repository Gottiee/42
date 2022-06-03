/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:41:18 by eedy              #+#    #+#             */
/*   Updated: 2022/06/03 12:32:27 by eedy             ###   ########.fr       */
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
# define ARGC_PRB 1
# define FD_PRB 2
# define MAP_PARSING_PRB 3
# define MAP_MALLOC_X_PRB 4

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

typedef struct	s_map
{
	int	x;
	int	y;
	int	color;
	int	z;
}				t_map;

/*          --- Fonction qui gere le parsing de MAP ---     */

void    map_parsing(char *file_name);
void	map_parsing_two(int fd, char ***map, char *str);
void	malloc_map_x(char ***map, int x_count);
int		count_x(char *str);

/*          --- Fonction qui gere les erreurs ---     */

void    error_center(int error, ...);
void    error_no_free(int error);
void    error_free_map_y(va_list ptr);
void    error_free_map_xy(char ***map, int i);

/*          --- Fonction principals ---     */

int main(int argc, char **argv);

#endif
