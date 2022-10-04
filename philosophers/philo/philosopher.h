/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:51:47 by eedy              #+#    #+#             */
/*   Updated: 2022/10/04 10:59:07 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define ARG_PRB 1
# define ATOY 2
# define ATOY_INTEGER 3
# define DEAD 4

typedef struct s_philo
{
	long long		f_t;
	int				stop;
	long long		getime;
	int				time_to_eat;
	int				time_to_die;
	int				nbr_philo;
	int				nbr_eaten_meal;
	int				time_to_sleep;
	int				arg;
	int				count_eat;
	int				*dead;
	int				*eat;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*mutex_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	*m_dead;
	pthread_mutex_t	m_stop;
	int				stop_print;
}				t_philo;

/*          --- Fonctions principals ---     */

/*Fichier: main.c*/
int			main(int argc, char **argv);
void		manage_philo(void);
void		*routine(void *arg);
void		while_philo(int bolo, int i, int j, int bolo2);
void		init_while(void);

/*Fichier: manage_philo.c*/
int			reduce_while(void);
int			main2(void);
int			init_manage(void);

/*          --- Fonctions qui gere les erreurs ---     */

/*Fichier: error.c*/
void		error(int err);

/*          --- Fonctions utils---     */

/*Fichier: utils.c*/
long		ft_atoi(const char *str);
long long	get_mili(void);
void		ft_bzero(int *s, int n);	
int			free_philo(void);
void		think_expended(void);

/*          --- Fonctions qui gere les structures ---     */

/*Fichier: struc.c*/
void		destroy_mutex(t_philo *philo);
void		init_struc(char **argv);	
t_philo		*get_struct(void);

/*          --- Fonctions qui gere la routine des threads---     */

/*Fichier: routine_even.c*/
int			end_unlock_next_fork(int philo_th);
int			end_unlock_next_previous_forks(int philo_th);	
int			even_none_egual_zero(int philo_th, long long getime);
int			even_thread(int philo_th, long long *getime);
int			even_egual_zero(int philo_th, long long getime);

/*Fichier: even.c*/
int			even_thread2(int philo_th, long long *getime);
int			routine2(int philo_th, long long *getime);
int			expend_routine(int philo_th, long long *getime);
int			eat_death(int philo_th, int bolo);

/*Fichier: while.c*/
int			stop_philo(void);
void		count_eat(int j, int *bolo2);
void		sleep2(int philo_th);
int			sleep3(int philo_th, long long *getime);

/*Fichier: routine_even2.c*/
int			end_unlock_both(int philo_th);
int			reset_time(int philo_th, long long *getime);
void		eat_death2(int philo_th);

/*Fichier: routine_odd.c*/
int			odd_thread(int philo_th, long long *getime);
int			end_unlock_previous_fork(int philo_th);
int			sleep_and_think(int philo_th, long long *getime);
int			tchek_print(int status);

#endif
