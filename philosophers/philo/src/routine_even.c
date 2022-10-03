/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_even.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:47:49 by eedy              #+#    #+#             */
/*   Updated: 2022/09/28 11:04:59 by eedy             ###   ########.fr       */
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
	if (tchek_print(DEAD))
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
	if (tchek_print(DEAD))
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
	t_philo			*philo;
	long long int	time;

	philo = get_struct();
	pthread_mutex_lock(philo->fork + philo_th - 1);
	pthread_mutex_lock(&(philo->m_stop));
	if (!philo->stop || get_mili() >= getime)
	{
			printf("philo %d arrive ici philo->stop = %d\n", philo_th, philo->stop);
		pthread_mutex_unlock(&(philo->m_stop));
		return (end_unlock_next_previous_forks(philo_th));
	}
	pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(&(philo->print));
	time = get_mili() - philo->f_t;
	if (tchek_print(0))
		printf("%lld %d has taken a fork\n", time, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	return (0);
}

int	even_egual_zero(int philo_th, long long getime)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_lock(philo->fork + philo->nbr_philo - 1);
	pthread_mutex_lock(&(philo->m_stop));
	if (!philo->stop || get_mili() >= getime)
	{
		pthread_mutex_unlock(&(philo->m_stop));
		pthread_mutex_unlock(philo->fork + philo->nbr_philo - 1);
		pthread_mutex_unlock(philo->fork + philo_th);
		return (-1);
	}
	pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(&(philo->print));
	if (tchek_print(0))
		printf("%lld %d has taken a fork\n", \
get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	return (0);
}

int	even_thread(int philo_th, long long *getime)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_lock(philo->fork + philo_th);
	pthread_mutex_lock(&(philo->m_stop));
	if (!philo->stop || get_mili() >= *getime)
		return (end_unlock_next_fork(philo_th));
	pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(&(philo->print));
	if (tchek_print(0))
		printf("%lld %d has taken a fork\n", \
get_mili() - philo->f_t, philo_th + 1);
	else
		printf("wtf\n");
	pthread_mutex_unlock(&(philo->print));
	if (philo_th != 0)
		if (even_none_egual_zero(philo_th, *getime) == -1)
			return (-1);
	if (philo_th == 0)
		if (even_egual_zero(philo_th, *getime) == -1)
			return (-1);
	pthread_mutex_lock(&(philo->m_stop));
	return (even_thread2(philo_th, getime));
}
