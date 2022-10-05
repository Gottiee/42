/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:33:03 by eedy              #+#    #+#             */
/*   Updated: 2022/10/04 10:59:33 by eedy             ###   ########.fr       */
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

int	eat_death(int philo_th, int bolo)
{
	t_philo	*philo;

	philo = get_struct();
	ft_usleep((philo->time_to_die) * 1000, NULL, philo_th);
	pthread_mutex_lock(&(philo->print));
	if (tchek_print(DEAD))
	{
		pthread_mutex_unlock(&(philo->print));
		pthread_mutex_lock(&(philo->print));
		printf("%lld %d died\n", get_mili() - philo->f_t, philo_th + 1);
		pthread_mutex_unlock(&(philo->print));
	}
	else
		pthread_mutex_unlock(&(philo->print));
	if (bolo == 1)
	{
		pthread_mutex_unlock(philo->fork + philo_th);
		if (philo_th != 0)
			pthread_mutex_unlock(philo->fork + philo_th - 1);
		else
			pthread_mutex_unlock(philo->fork + philo->nbr_philo - 1);
	}
	eat_death2(philo_th);
	return (-1);
}

int	even_thread2(int philo_th, long long *getime)
{
	t_philo	*philo;

	philo = get_struct();
	if (get_mili() > *getime || !philo->stop)
		return (end_unlock_both(philo_th));
	pthread_mutex_unlock(&(philo->m_stop));
	if (philo->time_to_eat <= philo->time_to_die)
	{
		if (reset_time(philo_th, getime) == -1)
			return (-1);
	}
	else
		return (eat_death(philo_th, 1));
	if (philo->eat[philo_th] == philo->nbr_eaten_meal)
		return (-1);
	return (0);
}
