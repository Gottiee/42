/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:53:46 by eedy              #+#    #+#             */
/*   Updated: 2022/08/25 15:30:27 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->nbr_philo)
		pthread_mutex_destroy(philo->fork + i);
	i = -1;
	while (++i < philo->nbr_philo)
		pthread_mutex_destroy(philo->mutex_eat + i);
	pthread_mutex_destroy(&(philo->print));
	i = -1;
	while (++i < philo->nbr_philo)
		pthread_mutex_destroy(philo->m_dead + i);
	pthread_mutex_destroy(&(philo->m_stop));
}

void	init_struc(char **argv)
{
	int		i;
	t_philo	*philo;

	philo = get_struct();
	i = -1;
	philo->stop = 1;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	while (++i < philo->nbr_philo)
		pthread_mutex_init(philo->fork + i, NULL);
	i = -1;
	while (++i < philo->nbr_philo)
		philo->dead[i] = 1;
	philo->stop = 1;
	if (argv[5])
		philo->nbr_eaten_meal = ft_atoi(argv[5]);
	else
	philo->nbr_eaten_meal = -1;
	ft_bzero(philo->eat, philo->nbr_philo);
	philo->count_eat = 0;
	i = -1;
	while (++i < philo->nbr_philo)
		pthread_mutex_init(philo->mutex_eat + i, NULL);
	pthread_mutex_init(&(philo->print), NULL);
	i = -1;
	while (++i < philo->nbr_philo)
		pthread_mutex_init(philo->m_dead + i, NULL);
	pthread_mutex_init(&(philo->m_stop), NULL);
}

t_philo	*get_struct(void)
{
	static t_philo	philo;	

	return (&philo);
}
