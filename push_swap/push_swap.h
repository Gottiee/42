/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:51:47 by eedy              #+#    #+#             */
/*   Updated: 2022/06/24 17:29:51 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.a/ft_printf.h"
# include "libft.a/libft/libft.h"
# include "libft.a/libft/get_next_line.h"

# define ERROR_ARG 1
# define SA 2
# define SB 3
# define SS 4
# define PA 5
# define PB 6
# define RA 7
# define RB 8
# define RR 9
# define RRA 10
# define RRB 11
# define RRR 12

typedef struct s_lists
{
	char 			*move;
	int				count_cout;
	struct s_lists	*next;
}				t_lists;

typedef struct s_count
{
	int	count_a;
	int	count_b;
}				t_count;

typedef struct s_rec
{
	int	*stack_a;
	int	*stack_b;
	int	argc;
	int	lower;
	int	hold_then;
	int	upper;
	int	hold_before;
	int	nbr_move_hold;
	int	nbr_move_upper;
	int	nbr_move_before;
	int	nbr_move_lower;
	int	no_push_lower;
	int	move_lower;
	int	move_upper;
	int	move_hold_then;
	int	move_hold_before;
	int	count;
	int	count_up;
}				t_rec;

/*          --- Fonctions qui gere le parsing de MAP ---     */

/*Fichier: arg_parsing.c*/
int		*arg_parsing(int argc, char **argv);
void	check_arg(char *str, int *stack);
void	fill_tab(int *stack, char **argv, int argc);

/*          --- Fonctions principals ---     */

/*Fichier: main.c*/
int		main(int argc, char **argv);


/*          --- Fonctions qui verifient le si le tableau est trie ---     */

/*Fichier: verif_tab.c*/
int		verif_tab(int *stack_a, t_count *count);

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

/*          --- Fonctions qui gerent les listes ---     */

/*Fichier: list.c*/
t_lists	*init_list(void);
int		add_new_list(t_lists *first, char *buffer, int malloc_size);
void	de_list(t_lists *first);
void	replace_list(int nbr_cout, char *buffer, int malloc_size, t_lists *first);
void	print_solution(t_lists *first);

/*Fichier: call_instruction.c*/
void	call_instructions(int k, t_rec *rec, t_count *count, t_lists *first);
void	instruction2(int k, t_rec *rec, t_count *count, t_lists *first);
void	instruction3(int k, t_rec *rec, t_count *count, t_lists *first);
void	instruction4(int k, t_rec *rec, t_count *count, t_lists *first);

/*          --- Fonctions qui gerent les algorythmes ---     */

/*Fichier: small_algo.c*/
void	small_algo(t_count *count, t_rec *rec, t_lists *list);
void	five_nbr_algo(t_count *count, t_rec *rec, t_lists *first);
void	small_algo2(t_count *count, t_rec *rec, t_lists *first);

/*Fichier: small_algo.c*/
void	one_undred_and_less(t_count *count, t_rec *rec, t_lists *first);
void	manage_lower(t_rec *rec, t_count *count, t_lists *first);
void	manage_lower2(int i, t_rec *rec, t_count *count, t_lists *first);
void	find_lower(t_rec *rec, t_count *count);
void	find_hold_then(t_rec *rec, t_count *count);
void	check_push(t_rec *rec, t_count *count);
#endif
