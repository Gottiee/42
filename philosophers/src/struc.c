/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:53:46 by eedy              #+#    #+#             */
/*   Updated: 2022/07/22 12:42:17 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->nbr_philo)
		pthread_mutex_destroy(philo->fork + i);
}

void	init_struc(t_philo *philo, char **argv)
{
	int	i;

	i = -1;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->nbr_eaten_meal = ft_atoi(argv[5]);
	while (++i < philo->nbr_philo)
		pthread_mutex_init(philo->fork + i, NULL);
	i = -1;
	while (++i < philo->nbr_philo)
		philo->dead[i] = 1;
	philo->stop = 1;
}

t_philo	*get_struct(void)
{
	static t_philo	philo;	

	return (&philo);
}
