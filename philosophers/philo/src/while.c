/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:31:24 by eedy              #+#    #+#             */
/*   Updated: 2022/10/03 18:06:55 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	sleep3(int philo_th, long long *getime)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_unlock(&(philo->m_stop));
	if (get_mili() < *getime)
	{
		pthread_mutex_lock(&(philo->print));
		if (tchek_print(0))
			printf("%lld %d is thinking\n", \
get_mili() - philo->f_t, philo_th + 1);
		pthread_mutex_unlock(&(philo->print));
		think_expended();
	}
	else
	{
		pthread_mutex_lock(philo->m_dead + philo_th);
		philo->dead[philo_th] = 0;
		pthread_mutex_unlock(philo->m_dead + philo_th);
		pthread_mutex_lock(&(philo->print));
		if (tchek_print(DEAD))
			printf("%lld %d died\n", get_mili() - philo->f_t, philo_th + 1);
		pthread_mutex_unlock(&(philo->print));
		return (-1);
	}
	return (0);
}

void	sleep_extension(int philo_th)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_unlock(&(philo->m_stop));
	usleep((philo->time_to_die - philo->time_to_eat) * 1000);
	pthread_mutex_lock(&(philo->print));
	if (tchek_print(DEAD))
		printf("%lld %d died\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_lock(philo->m_dead + philo_th);
	philo->dead[philo_th] = 0;
	pthread_mutex_unlock(philo->m_dead + philo_th);
	pthread_mutex_unlock(&(philo->print));
}

void	sleep2(int philo_th)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_lock(&(philo->m_stop));
	if (philo->stop
		&& philo->time_to_sleep < philo->time_to_die - philo->time_to_eat)
	{
		pthread_mutex_unlock(&(philo->m_stop));
		pthread_mutex_lock(&(philo->print));
		if (tchek_print(0))
			printf("%lld %d is sleeping\n", \
get_mili() - philo->f_t, philo_th + 1);
		pthread_mutex_unlock(&(philo->print));
		usleep(philo->time_to_sleep * 1000);
	}
	else if (philo->time_to_sleep >= philo->time_to_die - philo->time_to_eat)
		sleep_extension(philo_th);
	else
		pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(&(philo->m_stop));
}

int	stop_philo(void)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_lock(&(philo->m_stop));
	philo->stop = 0;
	pthread_mutex_unlock(&(philo->m_stop));
	usleep(100);
	return (-1);
}

void	count_eat(int j, int *bolo2)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_lock(philo->mutex_eat + j);
	if (philo->nbr_eaten_meal != -1 && philo->eat[j]
		>= philo->nbr_eaten_meal)
	{
		philo->count_eat++;
		*bolo2 = reduce_while();
	}
	pthread_mutex_unlock(philo->mutex_eat + j);
	usleep(100);
}
