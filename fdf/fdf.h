/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:41:18 by eedy              #+#    #+#             */
/*   Updated: 2022/06/02 15:09:53 by eedy             ###   ########.fr       */
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
# include "libft.a/libft.h"
# include "libft.a/libft/libft.h"
# include "libft.a/libft/get_next_line.h"

# define WINDOW_H 1080
# define WINDOW_W 1920
# define ARGC_PRB 1
# define FD_PRB 2

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

/*          --- Fonction qui gere les erreurs ---     */

void    error_center(int error);
void    error_no_free(int error);

/*          --- Fonction principals ---     */

int main(int argc, char **argv);

#endif
