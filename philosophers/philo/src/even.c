/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:33:03 by eedy              #+#    #+#             */
/*   Updated: 2022/09/27 17:50:36 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	expend_routine(int philo_th, long long *getime)
{
	t_philo		*philo;

	philo = get_struct();
	pthread_mutex_lock(&(philo->m_stop));
	if (philo_th % 2 == 0 && (get_mili() < *getime) && philo->stop)
	{
		pthread_mutex_unlock(&(philo->m_stop));
		if (even_thread(philo_th, getime) == -1)
			return (-1);
	}
	else
		pthread_mutex_unlock(&(philo->m_stop));
	return (0);
}

int	routine3(int philo_th)
{
	t_philo		*philo;

	philo = get_struct();
	if (!philo->dead[philo_th])
	{
		pthread_mutex_unlock(philo->m_dead + philo_th);
		return (-1);
	}
	else
		pthread_mutex_unlock(philo->m_dead + philo_th);
	pthread_mutex_lock(&(philo->m_stop));
	if (!philo->stop)
	{
		pthread_mutex_unlock(&(philo->m_stop));
		return (-1);
	}
	else
		pthread_mutex_unlock(&(philo->m_stop));
	return (0);
}

int	routine2(int philo_th, long long *getime)
{
	t_philo		*philo;

	philo = get_struct();
	pthread_mutex_lock(&(philo->m_stop));
	if (philo_th % 2 != 0 && (get_mili() < *getime) && philo->stop)
	{
		pthread_mutex_unlock(&(philo->m_stop));
		if (odd_thread(philo_th, getime) == -1)
			return (-2);
	}
	else
		pthread_mutex_unlock(&(philo->m_stop));
	if (sleep_and_think(philo_th, getime) == -1)
		return (-2);
	pthread_mutex_lock(philo->m_dead + philo_th);
	return (routine3(philo_th));
}

int	even_thread2(int philo_th, long long *getime)
{
	t_philo	*philo;

	philo = get_struct();
	if (get_mili() > *getime || !philo->stop)
		return (end_unlock_both(philo_th));
	pthread_mutex_unlock(&(philo->m_stop));
	if (reset_time(philo_th, getime) == -1)
		return (-1);
	if (philo->eat[philo_th] == philo->nbr_eaten_meal)
		return (-1);
	return (0);
}
