/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_even.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:47:49 by eedy              #+#    #+#             */
/*   Updated: 2022/08/25 17:08:11 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	end_unlock_next_fork(int philo_th)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_unlock(philo->fork + philo_th);
	pthread_mutex_lock(&(philo->print));
	printf("%lld %d died\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	pthread_mutex_lock(philo->m_dead + philo_th);
	philo->dead[philo_th] = 0;
	pthread_mutex_unlock(philo->m_dead + philo_th);
	return (-1);
}

int	end_unlock_next_previous_forks(int philo_th)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_unlock(philo->fork + philo_th);
	pthread_mutex_lock(&(philo->print));
	printf("%lld %d died\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	pthread_mutex_unlock(philo->fork + philo_th - 1);
	pthread_mutex_lock(philo->m_dead + philo_th);
	philo->dead[philo_th] = 0;
	pthread_mutex_unlock(philo->m_dead + philo_th);
	return (-1);
}

int	even_none_egual_zero(int philo_th, long long getime)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_lock(philo->fork + philo_th - 1);
	pthread_mutex_lock(&(philo->m_stop));
	if (!philo->stop || get_mili() > getime)
	{
		pthread_mutex_unlock(&(philo->m_stop));
		return (end_unlock_next_previous_forks(philo_th));
	}
	pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(&(philo->print));
	printf("%lld %d has taken a fork\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	return (0);
}

int	even_egual_zero(int philo_th, long long getime)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_lock(philo->fork + philo->nbr_philo - 1);
	pthread_mutex_lock(&(philo->m_stop));
	if (!philo->stop || get_mili() > getime)
	{
		pthread_mutex_unlock(&(philo->m_stop));
		pthread_mutex_unlock(philo->fork + philo->nbr_philo - 1);
		pthread_mutex_unlock(philo->fork + philo_th);
		return (-1);
	}
	pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(&(philo->print));
	printf("%lld %d has taken a fork\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	return (0);
}

int	even_thread(int philo_th, long long *getime)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_lock(philo->fork + philo_th);
	pthread_mutex_lock(&(philo->m_stop));
	if (!philo->stop || get_mili() > *getime)
		return (end_unlock_next_fork(philo_th));
	pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(&(philo->print));
	printf("%lld %d has taken a fork\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	if (philo_th != 0)
		if (even_none_egual_zero(philo_th, *getime) == -1)
			return (-1);
	if (philo_th == 0)
		if (even_egual_zero(philo_th, *getime) == -1)
			return (-1);
	pthread_mutex_lock(&(philo->m_stop));
	if (get_mili() > *getime || !philo->stop)
		return (end_unlock_both(philo_th));
	pthread_mutex_unlock(&(philo->m_stop));
	if (reset_time(philo_th, getime) == -1)
		return (-1);
	if (philo->eat[philo_th] == philo->nbr_eaten_meal)
		return (-1);
	return (0);
}
