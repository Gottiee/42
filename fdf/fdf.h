/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:41:18 by eedy              #+#    #+#             */
/*   Updated: 2022/06/03 17:25:17 by eedy             ###   ########.fr       */
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
	int	color;
	int	z;
}				t_map;

/*          --- Fonction qui gere le parsing de MAP ---     */

/*Fichier: map_parsing_two.c*/
void	put_data_struct(t_map *info_map, char *str, int x);
void	struc_fill(t_map *info_map, int nbr, char *str, int i);
int		deci_from_hexa(const char *hexa_str, char *hexa);
int		search_index(const char *hexa_str, char hexa);

/*Fichier: map_parsing.c*/

void	map_parsing(char *file_name);
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

/*          --- Fonction principals ---     */

/*Fichier: main.c*/
int main(int argc, char **argv);

#endif
