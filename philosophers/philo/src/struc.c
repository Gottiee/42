/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:53:46 by eedy              #+#    #+#             */
/*   Updated: 2022/10/05 17:13:45 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->nbr_philo)
		pthread_mutex_destroy(philo->fork + i);
	i = -1;
	while (++i < philo->nbr_philo)
		pthread_mutex_destroy(philo->mutex_eat + i);
	pthread_mutex_destroy(&(philo->print));
	i = -1;
	while (++i < philo->nbr_philo)
		pthread_mutex_destroy(philo->m_dead + i);
	pthread_mutex_destroy(&(philo->m_stop));
}

void	init_struc2(void)
{
	t_philo	*philo;
	int		i;

	philo = get_struct();
	ft_bzero(philo->eat, philo->nbr_philo);
	philo->count_eat = 0;
	i = -1;
	while (++i < philo->nbr_philo)
		pthread_mutex_init(philo->mutex_eat + i, NULL);
	pthread_mutex_init(&(philo->print), NULL);
	i = -1;
	while (++i < philo->nbr_philo)
		pthread_mutex_init(philo->m_dead + i, NULL);
	pthread_mutex_init(&(philo->m_stop), NULL);
	philo->stop_print = 0;
}

void	init_struc(char **argv)
{
	int		i;
	t_philo	*philo;

	philo = get_struct();
	i = -1;
	philo->stop = 1;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	while (++i < philo->nbr_philo)
		pthread_mutex_init(philo->fork + i, NULL);
	i = -1;
	while (++i < philo->nbr_philo)
		philo->dead[i] = 1;
	philo->stop = 1;
	if (argv[5])
		philo->nbr_eaten_meal = ft_atoi(argv[5]);
	else
		philo->nbr_eaten_meal = -1;
	init_struc2();
}

t_philo	*get_struct(void)
{
	static t_philo	philo;	

	return (&philo);
}

void	ft_usleep(long long time, long long *getime, int philo_th)
{
	long long	stop;
	t_philo		*philo;

	time /= 1000;
	philo = get_struct();
	stop = get_mili() + time;
	while (get_mili() < stop)
	{
		pthread_mutex_lock(&(philo->m_stop));
		if (getime && get_mili() >= *getime)
		{
			sleep_dead(philo_th);
			return ;
		}
		if (!philo->stop)
		{
			pthread_mutex_unlock(&(philo->m_stop));
			return ;
		}
		pthread_mutex_unlock(&(philo->m_stop));
		usleep(500);
	}
}
