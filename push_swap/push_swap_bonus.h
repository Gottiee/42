/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:08:28 by eedy              #+#    #+#             */
/*   Updated: 2022/06/15 13:02:37 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.a/ft_printf.h"
# include "libft.a/libft/libft.h"
# include "libft.a/libft/get_next_line.h"

typedef struct s_count
{
	int	a_count;
	int	b_count;
}				t_count;

/*          --- Fonctions principals ---     */

/*Fichier: main_bonus.c*/
int		main(int argc, char **argv);
void	read_terminal(int *stack_a, int *stack_b, t_count * count);
int		verif_buf(char *buf, int i);

/*          --- Fonctions qui checkent le buffer ---     */

/*Fichier: check_buffer.c*/


/*          --- Fonctions qui gere le parsing de MAP ---     */

/*Fichier: arg_parsing.c*/
int		*arg_parsing(int argc, char **argv);
void	check_arg(char *str, int *stack);
void	fill_tab(int *stack, char **argv, int argc);

/*          --- Fonctions qui gere la fin du program ---     */

/*Fichier: error.c*/
void	end_center(int event, ...);
void	error_arg(va_list ptr);

/*          --- Fonctions d'instruction (gestion de tableau) ---     */

/*Fichier: instruction*/
void	sa(int *stack_a, int argc);
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
