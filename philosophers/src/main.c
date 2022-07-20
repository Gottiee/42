/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:44:26 by eedy              #+#    #+#             */
/*   Updated: 2022/07/20 18:33:47 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;

	if (argc < 5 || argc > 6)		
		error(ARG_PRB);
	philo = get_struct();
	philo->nbr_philo = ft_atoi(argv[1]);
	philo->philo = malloc(sizeof(pthread_t) * (philo->nbr_philo + 1));
	if (!philo->philo)
		return (1);
	philo->philo[philo->nbr_philo] = 0;
	philo->fork = malloc(sizeof(pthread_mutex_t) * (philo->nbr_philo + 1));
	if (!philo->fork)
		return (2);
	init_struc(philo, argv);

	/*fin du program apres ce commentaire*/	
	destroy_mutex(philo);
	free(philo->fork);
	free(philo->philo);
}
