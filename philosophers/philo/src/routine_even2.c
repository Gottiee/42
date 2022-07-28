/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_even2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:20:56 by eedy              #+#    #+#             */
/*   Updated: 2022/07/28 17:07:26 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	end_unlock_both(int philo_th)
{
	t_philo	*philo;

	philo = get_struct();
	philo->dead[philo_th] = 0;
	printf("%lld %d died\n", get_mili() - philo->f_t, philo_th);
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
	printf("%lld %d is eating\n", get_mili() - philo->f_t, philo_th);
	philo->eat[philo_th] += 1;
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
	if (philo->stop)
	{
		printf("%lld %d is sleeping\n", get_mili() - philo->f_t, philo_th);
		usleep(philo->time_to_sleep * 1000);
	}
	if (philo->stop)
	{
		if (get_mili() < *getime)
			printf("%lld %d is thinking\n", get_mili() - philo->f_t, philo_th);
		else
		{
			philo->dead[philo_th] = 0;
			printf("%lld %d died\n", get_mili() - philo->f_t, philo_th);
			return (-1);
		}
	}
	return (0);
}
