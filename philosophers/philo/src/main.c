/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:44:26 by eedy              #+#    #+#             */
/*   Updated: 2022/07/27 13:50:41 by eedy             ###   ########.fr       */
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
	philo->fork = malloc(sizeof(pthread_mutex_t) * (philo->nbr_philo + 1));
	philo->dead = malloc(sizeof(int) * (philo->nbr_philo + 1));
	if (!philo->fork || !philo->dead)
	{
		free(philo->fork);
		free(philo->dead);
		return (1);
	}
	init_struc(argv);
	philo->philo = malloc(sizeof(pthread_t) * (philo->nbr_philo + 1));
	if (!philo->philo)
	{
		free(philo->fork);
		free(philo->dead);
		return (2);
	}
	// gerer la valeur de renvoie de manage philo
	manage_philo();

	/*fin du program apres ce commentaire*/	
	destroy_mutex(philo);
	free(philo->fork);
	free(philo->philo);
	free(philo->dead);
}

int	manage_philo(void)
{
	int		i;
	int		bolo;
	int		*index;
	t_philo	*philo;

	philo = get_struct();
	bolo = 0;
	

	//set up des des miliseconde de base
	philo->first_time = get_mili();

	// si il n'y a qu'un philosophe
	if (philo->nbr_philo == 1)
	{
		usleep(philo->time_to_die * 1000);
		printf("%lld %d died\n", get_mili() - philo->first_time , 0);
		return (1);
	}

	index = malloc(sizeof(int) * (philo->nbr_philo + 1));
	if (!index)
		return (0);
	//creation des philosophes
	i = -1;
	while (++i < philo->nbr_philo)
	{
		index[i] = i;
		pthread_create(philo->philo + i, NULL, &routine, index + i);
	}

	//attente de la mort d'un philo pour envoy le signal a tout le monde de mourir
	while (1) // rajouter la condition de philo->nbr_eaten_meal pour sortir de la boucle 
	{
		i = -1;
		while (++i < philo->nbr_philo)
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
	while (++i < philo->nbr_philo)
		pthread_join(philo->philo[i], NULL);
	free(index);
	return (1);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	int			philo_th;
	long long	getime;

	philo_th = *(int *)arg;
	philo = get_struct();
	getime = get_mili() + (long long)philo->time_to_die;
	
	//tant que mon main n'a pas passer la valeur de stop a 0 ou que notre current philo est encore en vie
	while (philo->stop && philo->dead[philo_th])
	{
		//les philos manges les paire d'abord
		
		if (philo_th % 2 == 0 && (get_mili() < getime) && philo->stop)
		{
			pthread_mutex_lock(philo->fork + philo_th);
			if (!philo->stop || get_mili() > getime)
			{
					pthread_mutex_unlock(philo->fork + philo_th);
					printf("%lld %d died\n", get_mili() - philo->first_time , philo_th);
					philo->dead[philo_th] = 0;
					return (NULL);
			}
			printf("%lld %d has taken a fork\n", get_mili() - philo->first_time , philo_th);
			if (philo_th != 0)
			{
				pthread_mutex_lock(philo->fork + philo_th - 1);
				if (!philo->stop || get_mili() > getime)
				{
					pthread_mutex_unlock(philo->fork + philo_th);
					printf("%lld %d died\n", get_mili() - philo->first_time , philo_th);
					pthread_mutex_unlock(philo->fork + philo_th - 1);
					philo->dead[philo_th] = 0;
					return (NULL);
				}
				printf("%lld %d has taken a fork\n", get_mili() - philo->first_time , philo_th);
			}
			else 
			{
				pthread_mutex_lock(philo->fork + philo->nbr_philo - 1);
				if (!philo->stop || get_mili() > getime)
				{
					pthread_mutex_unlock(philo->fork + philo_th);
					pthread_mutex_unlock(philo->fork + philo->nbr_philo - 1);
					printf("%lld %d died\n", get_mili() - philo->first_time , philo_th);
					philo->dead[philo_th] = 0;
					return (NULL);
				}
				printf("%lld %d has taken a fork\n", get_mili() - philo->first_time , philo_th);
			}
			if (get_mili() > getime || !philo->stop)
			{
				philo->dead[philo_th] = 0;
				printf("%lld %d died\n", get_mili() - philo->first_time , philo_th);
				if (philo_th != 0) 
					pthread_mutex_unlock(philo->fork + philo_th - 1);
				else
					pthread_mutex_unlock(philo->fork + philo->nbr_philo - 1);
				return (NULL);
			}
			printf("%lld %d is eating\n", get_mili() - philo->first_time , philo_th);
			usleep(philo->time_to_eat * 1000);
			pthread_mutex_unlock(philo->fork + philo_th);
			if (philo_th != 0)
				pthread_mutex_unlock(philo->fork + philo_th - 1);
			else
				pthread_mutex_unlock(philo->fork + philo->nbr_philo - 1);
		}

		//les impaires mangent
		else if (philo_th % 2 != 0 && (get_mili() < getime) && philo->stop)
		{
			pthread_mutex_lock(philo->fork + philo_th - 1);
			if (!philo->stop || get_mili() > getime)
			{
				pthread_mutex_unlock(philo->fork + philo_th - 1);
				philo->dead[philo_th] = 0;
				printf("%lld %d died\n", get_mili() - philo->first_time , philo_th);
				return (NULL);
			}
			printf("%lld %d has taken a fork\n", get_mili() - philo->first_time , philo_th);
			pthread_mutex_lock(philo->fork + philo_th);
			if (!philo->stop || get_mili() > getime)
			{
				pthread_mutex_unlock(philo->fork + philo_th - 1);
				pthread_mutex_unlock(philo->fork + philo_th);
				printf("%lld %d died\n", get_mili() - philo->first_time , philo_th);
				philo->dead[philo_th] = 0;
				return (NULL);
			}
			printf("%lld %d has taken a fork\n", get_mili() - philo->first_time , philo_th);
			if (get_mili() > getime || !philo->stop)
			{
				philo->dead[philo_th] = 0;
				printf("%lld %d died\n", get_mili() - philo->first_time , philo_th);
				pthread_mutex_unlock(philo->fork + philo_th);
				pthread_mutex_unlock(philo->fork + philo_th - 1);
				return (NULL);
			}
			printf("%lld %d is eating\n", get_mili() - philo->first_time , philo_th);
			usleep(philo->time_to_eat * 1000);
			pthread_mutex_unlock(philo->fork + philo_th);
			pthread_mutex_unlock(philo->fork + philo_th - 1);
		}
		//reset du temps de vie
		getime = get_mili() + (long long)philo->time_to_die;

		//les philos dorment
		if (philo->stop)
		{
			printf("%lld %d is sleeping\n", get_mili() - philo->first_time , philo_th);
			usleep(philo->time_to_sleep * 1000);
		}
		if (philo->stop)
		{
			if (get_mili() < getime)
				printf("%lld %d is thinking\n", get_mili() - philo->first_time , philo_th);
			else
			{
				philo->dead[philo_th] = 0;
				printf("%lld %d died\n", get_mili() - philo->first_time, philo_th);
				return (NULL);
			}
		}
	}
	philo->dead[philo_th] = 0;
	return (NULL);
}
