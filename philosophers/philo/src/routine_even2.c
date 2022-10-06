/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_even2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:20:56 by eedy              #+#    #+#             */
/*   Updated: 2022/10/06 12:43:17 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	eat_death2(int philo_th)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_lock(philo->m_dead + philo_th);
	philo->dead[philo_th] = 0;
	pthread_mutex_unlock(philo->m_dead + philo_th);
}

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
	if (tchek_print(DEAD))
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
	if (tchek_print(0))
		printf("%lld %d is eating\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	pthread_mutex_lock(philo->mutex_eat + philo_th);
	philo->eat[philo_th] += 1;
	pthread_mutex_unlock(philo->mutex_eat + philo_th);
	*getime = get_mili() + (long long)philo->time_to_die;
	ft_usleep(philo->time_to_eat * 1000, getime, philo_th);
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
	sleep2(philo_th, getime);
	if (philo->stop)
	{
		if (sleep3(philo_th, getime) == -1)
			return (-1);
	}
	else
		pthread_mutex_unlock(&(philo->m_stop));
	return (0);
}
