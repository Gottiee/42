/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:44:26 by eedy              #+#    #+#             */
/*   Updated: 2022/08/02 14:15:12 by eedy             ###   ########.fr       */
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
	philo->mutex_eat = malloc(sizeof(pthread_mutex_t) * (philo->nbr_philo + 1));
	philo->m_dead = malloc(sizeof(pthread_mutex_t) * (philo->nbr_philo + 1));
	if (!philo->fork || !philo->dead || !philo->eat || !philo->mutex_eat ||
		!philo->m_dead)
	{
		free(philo->fork);
		free(philo->mutex_eat);
		free(philo->eat);
		free(philo->dead);
		free(philo->m_dead);
		return (1);
	}
	init_struc(argv);
	if (main2() == -1)
		return (2);
}

void	init_while(void)
{
	int	bolo;	
	int	i;
	int	j;
	int	bolo2;

	bolo = 0;
	bolo2 = 0;
	i = -1;
	j = -1;
	while_philo(bolo, i, j, bolo2);
}

void	while_philo(int bolo, int i, int j, int bolo2)
{
	t_philo	*philo;

	philo = get_struct();
	while (1)
	{
		i = -1;
		while (++i < philo->nbr_philo)
		{
			pthread_mutex_lock(philo->m_dead + i);
			if (philo->dead[i] == 0)
				bolo = 1;
			pthread_mutex_unlock(philo->m_dead + i);
		} 
		j = -1;
		philo->count_eat = 0;

		while(++j < philo->nbr_philo)
		{
			pthread_mutex_lock(philo->mutex_eat + j);
			if (philo->eat[j] >= philo->nbr_eaten_meal)
			{
				philo->count_eat++;
				bolo2 = reduce_while();
			}
			pthread_mutex_unlock(philo->mutex_eat + j);
		}
		if (bolo)
		{
			pthread_mutex_lock(&(philo->m_stop));
			philo->stop = 0;
			pthread_mutex_unlock(&(philo->m_stop));
			usleep(100);
			break ;
		}
		if (bolo2)
			break ;
	}
}

void	manage_philo(void)
{
	t_philo	*philo;
	int		i;

	philo = get_struct();
	if (init_manage() == -1)
		return ;
	init_while();
	if (philo->nbr_philo > 5000)
		usleep(7000 * 1000);
	else if (philo->nbr_philo > 50)
		usleep(2000 * 1000);
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
	while (1)
	{
		if (philo_th % 2 == 0 && (get_mili() < getime) && philo->stop)
			if (even_thread(philo_th, &getime) == -1)
				return (NULL);
		if (philo_th % 2 != 0 && (get_mili() < getime) && philo->stop)
			if (odd_thread(philo_th, &getime) == -1)
				return (NULL);
		if (sleep_and_think(philo_th, &getime) == -1)
			return (NULL);
		pthread_mutex_lock(philo->m_dead + philo_th);
		if (!philo->dead[philo_th])
		{
			pthread_mutex_unlock(philo->m_dead + philo_th);
			break ;
		}
		pthread_mutex_unlock(philo->m_dead + philo_th);
		pthread_mutex_lock(&(philo->m_stop));
		if (!philo->stop)
		{
			pthread_mutex_unlock(&(philo->m_stop));
			break ;
		}
		pthread_mutex_unlock(&(philo->m_stop));
	}
	pthread_mutex_lock(philo->m_dead + philo_th);
	philo->dead[philo_th] = 0;
	pthread_mutex_unlock(philo->m_dead + philo_th);
	return (NULL);
}
