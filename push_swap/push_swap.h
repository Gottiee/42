/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:51:47 by eedy              #+#    #+#             */
/*   Updated: 2022/06/14 18:37:08 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.a/ft_printf.h"
# include "libft.a/libft/libft.h"
# include "libft.a/libft/get_next_line.h"

# define ERROR_ARG 1

typedef struct s_count
{
	int	a_count;
	int	b_count;
}				t_count;

/*          --- Fonction qui gere le parsing de MAP ---     */

/*Fichier: arg_parsing.c*/
int		*arg_parsing(int argc, char **argv);
void	check_arg(char *str, int *stack);
void	fill_tab(int *stack, char **argv, int argc);

/*          --- Fonction principals ---     */

/*Fichier: main.c*/
int		main(int argc, char **argv);

/*          --- Fonction qui gere le parsing de MAP ---     */

/*Fichier: error.c*/
void	end_center(int event, ...);
void	error_arg(va_list ptr);

/*          --- Fonction de tri ---     */

/*Fichier: instruction*/
void	sa(int *stack_a, int argc);
#endif
