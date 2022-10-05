/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:59:24 by eedy              #+#    #+#             */
/*   Updated: 2022/10/05 16:48:48 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	error(int err)
{
	t_philo	*philo;

	philo = get_struct();
	if (err == ARG_PRB)
	{
		printf("Arg problem, to few or to many args !\n");
		exit(1);
	}
	if (err == ATOY)
	{
		printf("Can't accept negativ, null or float value.\n");
		free(philo->fork);
		free(philo->eat);
		free(philo->dead);
		exit(1);
	}
	if (err == ATOY_INTEGER)
	{
		printf("Out of the integer range.\n");
		free(philo->fork);
		free(philo->eat);
		free(philo->dead);
		exit(1);
	}
}

void	sleep_dead(int philo_th)
{
	t_philo	*philo;

	philo = get_struct();
	pthread_mutex_unlock(&(philo->m_stop));
	pthread_mutex_lock(&(philo->print));
	if (tchek_print(DEAD))
		printf("%lld %d died\n", get_mili() - philo->f_t, philo_th + 1);
	pthread_mutex_unlock(&(philo->print));
	pthread_mutex_lock(philo->m_dead + philo_th);
	philo->dead[philo_th] = 0;
	pthread_mutex_unlock(philo->m_dead + philo_th);
}
