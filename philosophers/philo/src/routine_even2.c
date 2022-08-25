/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_even2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:20:56 by eedy              #+#    #+#             */
/*   Updated: 2022/08/25 17:08:41 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	end_unlock_both(int philo_th)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(philo->m_dead + philo_th);
	philo->dead[philo_th] = 0;
	pthread_mutex_unlock(philo->m_dead + philo_th);
	pthread_mutex_lock(&(philo->print));
	pthread_mutex_unlock(philo->fork + philo_th);
	printf("%lld %d died\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	if (philo_th != 0)
		pthread_mutex_unlock(philo->fork + philo_th - 1);
	else
		pthread_mutex_unlock(philo->fork + philo->nbr_philo - 1);
	return (-1);
}

int	reset_time(int philo_th, long long *getime)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_lock(&(philo->print));
	printf("%lld %d is eating\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));

	//lock le eat

	pthread_mutex_lock(philo->mutex_eat + philo_th);
	philo->eat[philo_th] += 1;
	pthread_mutex_unlock(philo->mutex_eat + philo_th);
	*getime = get_mili() + (long long)philo->time_to_die + 1;
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->fork + philo_th);
	if (philo_th != 0)
		pthread_mutex_unlock(philo->fork + philo_th - 1);
	else
		pthread_mutex_unlock(philo->fork + philo->nbr_philo - 1);
	return (0);
}

int	sleep_and_think(int philo_th, long long *getime)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_lock(&(philo->m_stop));
	if (philo->stop)
	{
		pthread_mutex_unlock(&(philo->m_stop));
		pthread_mutex_lock(&(philo->print));
		printf("%lld %d is sleeping\n", get_mili() - philo->f_t, philo_th + 1);
		pthread_mutex_unlock(&(philo->print));
		usleep(philo->time_to_sleep * 1000);
	}
	else
		pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(&(philo->m_stop));
	if (philo->stop)
	{
		pthread_mutex_unlock(&(philo->m_stop));
		if (get_mili() < *getime)
		{
			pthread_mutex_lock(&(philo->print));
			printf("%lld %d is thinking\n", get_mili() - philo->f_t, philo_th + 1);
			pthread_mutex_unlock(&(philo->print));
		}
		else
		{
			pthread_mutex_lock(philo->m_dead + philo_th);
			philo->dead[philo_th] = 0;
			pthread_mutex_unlock(philo->m_dead + philo_th);
			pthread_mutex_lock(&(philo->print));
			printf("%lld %d died\n", get_mili() - philo->f_t, philo_th + 1);
			pthread_mutex_unlock(&(philo->print));
			return (-1);
		}
	}
	else
		pthread_mutex_unlock(&(philo->m_stop));
	return (0);
}
