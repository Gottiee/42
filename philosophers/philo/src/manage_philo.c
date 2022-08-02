/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:52:44 by eedy              #+#    #+#             */
/*   Updated: 2022/08/02 14:20:18 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	reduce_while(void)
{
	t_philo	*philo;

	philo = get_struct();
	if (philo->count_eat == philo->nbr_philo)
		return (1);
	return (0);
}

int	main2(void)
{
	t_philo	*philo;

	philo = get_struct();
	philo->philo = malloc(sizeof(pthread_t) * (philo->nbr_philo + 1));
	if (!philo->philo)
	{
		free(philo->fork);
		free(philo->dead);
		free(philo->eat);
		free(philo->mutex_eat);
		free(philo->m_dead);
		return (-1);
	}
	manage_philo();
	destroy_mutex(philo);
	free(philo->fork);
	free(philo->philo);
	free(philo->dead);
	free(philo->eat);
	free(philo->mutex_eat);
	free(philo->m_dead);
	return (0);
}

int	init_manage(void)
{
	t_philo	*philo;
	int		i;
	int		*index;

	philo = get_struct();
	philo->f_t = get_mili();
	if (philo->nbr_philo == 1)
	{
		usleep(philo->time_to_die * 1000);
		printf("%lld %d died\n", get_mili() - philo->f_t, 0);
		return (-1);
	}
	index = malloc(sizeof(int) * (philo->nbr_philo + 1));
	if (!index)
		return (-1);
	i = -1;
	while (++i < philo->nbr_philo)
	{
		index[i] = i;
		pthread_create(philo->philo + i, NULL, &routine, index + i);
		usleep(5);
	}
	usleep(1000);
	free(index);
	return (0);
}
