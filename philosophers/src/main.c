/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:44:26 by eedy              #+#    #+#             */
/*   Updated: 2022/07/22 12:41:07 by eedy             ###   ########.fr       */
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
	init_struc(philo, argv);
	philo->dead = malloc(sizeof(int) * (philo->nbr_philo + 1));
	philo->philo = malloc(sizeof(pthread_t) * (philo->nbr_philo + 1));
	philo->fork = malloc(sizeof(pthread_mutex_t) * (philo->nbr_philo + 1));
	if (!philo->fork || !philo->philo || !philo->dead)
	{
		free(philo->fork);
		free(philo->philo);
		free(philo->dead);
	}
	// gerer la valeur de renvoie de manage philo
	manage_philo(philo);

	/*fin du program apres ce commentaire*/	
	destroy_mutex(philo);
	free(philo->fork);
	free(philo->philo);
}

int	manage_philo(t_philo *philo)
{
	int	i;
	int	bolo;
	int	*index;

	bolo = 0;
	index = malloc(sizeof(int) * (philo->nbr_philo + 1));
	if (!index)
		return (0);

	//creation
	i = -1;
	while (++i < philo->nbr_philo)
	{
		index[i] = i;
		pthread_creat(philo->philo + i, NULL, &routine, index + i);
	}

	//attente de la mort d'un philo pour envoy le signal a tout le monde de mourir
	while (1) // rajouter la condition de philo->nbr_eaten_meal pour sortir de la boucle 
	{
		i = -1;
		while (++i < phil->nbr_philo)
			if (philo->dead[i] == 0)
				bolo = 1;
		if (bolo)
		{
			philo->stop = 0;
			break ;
		}
	}

	//attente et destuction du thread
	i = -1;
	while (++1 < philo->nbr_philo)
		pthread_join(philo->philo[i], NULL);
	free(index);
	return (1);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	int			philo_th;

	philo_th = *(int *)arg;
	philo = get_struct();
	philo->getime = get_mili() + (long long)philo->time_to_die;
	
	//tant que mon main n'a pas passer la valeur de stop a 0 ou que notre current philo est encore en vie
	while (philo->stop && philo->dead[philo_th])
	{
		//les philos manges les impaire d'abord
		if (philo_th % 2 != 0 && (get_mili() < philo->getime))
		{
			pthread_mutex_lock(philo->fork + philo_th);
			pthread_mutex_lock(philo->fork + philo_th - 1);
			printf("%lld %d has taken a fork\n", get_mili(), philo_th);
			printf("%lld %d is eating\n", get_mili(), philo_th);
			usleep(philo->time_to_eat);
			pthread_mutex_unlock(philo->fork + philo_th)
			pthread_mutex_unlock(philo->fork + philo_th - 1);
		}
		else if (philo_th % 2 != 0 && (get_mili() < philo->getime))
		{
			pthread_mutex_lock(philo->fork + philo_th);
			if (philo_th != 0)
				pthread_mutex_lock(philo->fork + philo_th - 1);
			else
				pthread_mutex_lock(philo->fork + philo->nbr_philo);
			printf("%lld %d has taken a fork\n", get_mili(), philo_th);
			printf("%lld %d is eating\n", get_mili(), philo_th);
			usleep(philo->time_to_eat);
			pthread_mutex_unlock(philo->fork + philo_th)
			if (philo_th != 0)
				pthread_mutex_unlock(philo->fork + philo_th - 1);
			else
				pthread_mutex_unlock(philo->fork + philo->nbr_philo);
		}
		// le philo a pas eu le temps de manger et est mort
		else
		{
			philo->dead[philo_th] = 0;
			printf("%lld %d died\n", get_mili(), philo_th);
		}
		//reset du temps de vie
		philo->getime = get_mili() + (long long)philo->time_to_die;

		//les philos dorment
		printf("%lld %d is sleeping\n", get_mili(), philo_th);
		usleep(philo->time_to_sleep);
		if (get_mili() < philo->getime)
			printf("%lld %d is thinking\n", get_mili(), philo_th);
		else
		{
			philo->dead[philo_th] = 0;
			printf("%lld %d died\n", get_mili(), philo_th);
		}
	}
}
