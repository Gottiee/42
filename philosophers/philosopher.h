/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:51:47 by eedy              #+#    #+#             */
/*   Updated: 2022/07/25 12:57:30 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define ARG_PRB 1
# define ATOY 2
# define ATOY_INTEGER 3

typedef struct s_philo
{
	long long		first_time;
	int				stop;
	long long		getime;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	int				*dead;
	int				time_to_eat;
	int				time_to_die;
	int				nbr_philo;
	int				nbr_eaten_meal;
	int				time_to_sleep;
}				t_philo;

/*          --- Fonctions principals ---     */

/*Fichier: main.c*/
int			main(int argc, char **argv);
int			manage_philo(t_philo *philo);
void		*routine(void *arg);

/*          --- Fonctions qui gere les erreurs ---     */

/*Fichier: error.c*/
void		error(int err);

/*          --- Fonctions utils---     */

/*Fichier: utils.c*/
long		ft_atoi(const char *str);
long long	get_mili(void);

/*          --- Fonctions qui gere les structures ---     */

/*Fichier: struc.c*/
void		destroy_mutex(t_philo *philo);
void		init_struc(char **argv);	
t_philo		*get_struct(void);
#endif
