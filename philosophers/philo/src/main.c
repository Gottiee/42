/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:44:26 by eedy              #+#    #+#             */
/*   Updated: 2022/07/28 17:48:46 by eedy             ###   ########.fr       */
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
	if (philo->nbr_philo > 7000)
	{
		printf("To many philosophes.\n");
		return (1);
	}
	philo->fork = malloc(sizeof(pthread_mutex_t) * (philo->nbr_philo + 1));
	philo->dead = malloc(sizeof(int) * (philo->nbr_philo + 1));
	philo->eat = malloc(sizeof(int) * (philo->nbr_philo + 1));
	if (!philo->fork || !philo->dead || !philo->eat)
	{
		free(philo->fork);
		free(philo->eat);
		free(philo->dead);
		return (1);
	}
	init_struc(argv);
	philo->philo = malloc(sizeof(pthread_t) * (philo->nbr_philo + 1));
	if (!philo->philo)
	{
		free(philo->fork);
		free(philo->dead);
		free(philo->eat);
		return (2);
	}
	// gerer la valeur de renvoie de manage philo

	manage_philo();
		

	/*fin du program apres ce commentaire*/	
	destroy_mutex(philo);
	free(philo->fork);
	free(philo->philo);
	free(philo->dead);
	free(philo->eat);
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
		printf("%lld %d died\n", get_mili() - philo->f_t , 0);
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
	}
	free(index);
	return (0);
}

void	manage_philo(void)
{
	int		bolo;
	t_philo	*philo;
	int		i;

	philo = get_struct();
	bolo = 0;
	if (init_manage() == -1)
		return ;
	while (1)
	{
		i = -1;
		while (++i < philo->nbr_philo)
		{
			if (philo->dead[i] == 0)
				bolo = 1;
			if (philo->eat[i] == philo->nbr_eaten_meal)
				philo->count_eat++;		
		}
		if (bolo)
		{
			philo->stop = 0;
			break ;
		}
		if (philo->count_eat == philo ->nbr_philo)
			break;
	}
	if (philo->nbr_philo > 5000 || philo->nbr_eaten_meal == 1)
		usleep(7000 * 1000);
	else if (philo->nbr_philo > 50)
		usleep(2000 * 1000);

	printf("finis de dormir\n");
	//attente et destuction du thread
	i = -1;
	while (++i < philo->nbr_philo)
		pthread_join(philo->philo[i], NULL);
	return ;
}

void	*routine(void *arg)
{
	t_philo		*philo;
	int			philo_th;
	long long	getime;

	philo_th = *(int *)arg;
	philo = get_struct();
	getime = get_mili() + (long long)philo->time_to_die;
	while (philo->stop && philo->dead[philo_th])
	{
		if (philo_th % 2 == 0 && (get_mili() < getime) && philo->stop)
			if (even_thread(philo_th, &getime) == -1)
				return (NULL);
		if (philo_th % 2 != 0 && (get_mili() < getime) && philo->stop)
			if (odd_thread(philo_th, &getime) == -1)
				return (NULL);
		if (sleep_and_think(philo_th, &getime) == -1)
			return (NULL);
	}
	philo->dead[philo_th] = 0;
	return (NULL);
}
