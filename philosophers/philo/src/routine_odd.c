/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_odd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:45:13 by eedy              #+#    #+#             */
/*   Updated: 2022/08/25 17:08:57 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	end_unlock_previous_fork(int philo_th)
{
	t_philo		*philo;

	philo = get_struct();
	pthread_mutex_unlock(philo->fork + philo_th - 1);
	pthread_mutex_lock(philo->m_dead + philo_th);
	philo->dead[philo_th] = 0;
	pthread_mutex_unlock(philo->m_dead + philo_th);
	pthread_mutex_lock(&(philo->print));
	printf("%lld %d died\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	return (-1);
}

int	odd_thread(int philo_th, long long *getime)
{
	t_philo		*philo;

	philo = get_struct();
	pthread_mutex_lock(philo->fork + philo_th - 1);
	pthread_mutex_lock(&(philo->m_stop));
	if (!philo->stop || get_mili() > *getime)
	{
		pthread_mutex_unlock(&(philo->m_stop));
		return (end_unlock_previous_fork(philo_th));
	}
	pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(&(philo->print));
	printf("%lld %d has taken a fork\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	pthread_mutex_lock(philo->fork + philo_th);
	pthread_mutex_lock(&(philo->m_stop));
	if (!philo->stop || get_mili() > *getime)
	{
		pthread_mutex_unlock(&(philo->m_stop));
		return (end_unlock_next_previous_forks(philo_th));
	}
	pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(&(philo->print));
	printf("%lld %d has taken a fork\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	pthread_mutex_lock(&(philo->m_stop));
	if (get_mili() > *getime || !philo->stop)
	{
		pthread_mutex_unlock(&(philo->m_stop));
		return (end_unlock_next_previous_forks(philo_th));
	}
	pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(&(philo->print));
	printf("%lld %d is eating\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	pthread_mutex_lock(philo->mutex_eat + philo_th);
	philo->eat[philo_th] += 1;
	pthread_mutex_unlock(philo->mutex_eat + philo_th);
	*getime = get_mili() + (long long)philo->time_to_die + 1;
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->fork + philo_th);
	pthread_mutex_unlock(philo->fork + philo_th - 1);
	pthread_mutex_lock(philo->mutex_eat + philo_th);
	if (philo->eat[philo_th] == philo->nbr_eaten_meal)
	{
		pthread_mutex_unlock(philo->mutex_eat + philo_th);
		return (-1);
	}
	pthread_mutex_unlock(philo->mutex_eat + philo_th);
	return (0);
}
