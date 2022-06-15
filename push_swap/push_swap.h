/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:51:47 by eedy              #+#    #+#             */
/*   Updated: 2022/06/15 15:55:32 by eedy             ###   ########.fr       */
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
	int	count_a;
	int	count_b;
}				t_count;

/*          --- Fonctions qui gere le parsing de MAP ---     */

/*Fichier: arg_parsing.c*/
int		*arg_parsing(int argc, char **argv);
void	check_arg(char *str, int *stack);
void	fill_tab(int *stack, char **argv, int argc);

/*          --- Fonctions principals ---     */

/*Fichier: main.c*/
int		main(int argc, char **argv);

/*          --- Fonctions qui gere la fin du program ---     */

/*Fichier: error.c*/
void	end_center(int event, ...);
void	error_arg(va_list ptr);


/*          --- Fonctions d'instruction (gestion de tableau) ---     */

/*Fichier: instruction*/
void	sa(int *stack_a, t_count *count);
void	sb(int *stack_b, t_count *count);
void	ss(int *stack_a, int *stack_b, t_count *count);
void	pa(int *stack_a, int *stack_b, t_count *count);
void	up_stack_b(int *stack_b, t_count *count);

/*Fichier: instruction_2*/
void	pb(int *stack_a, int *stack_b, t_count *count);
void	up_stack_a(int *stack_a, t_count *count);
void	rra(int *stack_a, t_count *count);
void	rrb(int *stack_b, t_count *count);
void	rrr(int *stack_a, int *stack_b, t_count *count);

/*Fichier: instruction_3*/
void	ra(int *stack_a, t_count *count);
void	rb(int *stack_b, t_count *count);
void	rr(int *stack_a, int *stack_b, t_count *count);

#endif
