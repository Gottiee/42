/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:01 by eedy              #+#    #+#             */
/*   Updated: 2022/10/06 13:39:29 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	think_expended(long long *getime, int philo_th)
{
	t_philo	*philo;
	int		time_sleep;
	int		else_time;

	philo = get_struct();
	else_time = philo->time_to_die - \
philo->time_to_eat - philo->time_to_sleep - 100;
	time_sleep = philo->time_to_eat - philo->time_to_sleep;
	if (time_sleep <= 0)
	{
		if (else_time > 0)
			ft_usleep(else_time * 1000, getime, philo_th);
	}
	else
		ft_usleep((philo->time_to_eat - \
philo->time_to_sleep) * 1000 - 10, getime, philo_th);
}

int	free_philo(void)
{
	t_philo		*philo;

	philo = get_struct();
	free(philo->fork);
	free(philo->mutex_eat);
	free(philo->eat);
	free(philo->dead);
	free(philo->m_dead);
	return (1);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			error(ATOY);
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i ++;
	}
	if (str[i] != '\0')
		error(ATOY);
	if (nbr == 0 || str[i] == '.' || str[i] == ',')
		error(ATOY);
	if (nbr > 2147483647 || nbr < -2147483648)
		error(ATOY_INTEGER);
	return (nbr);
}

long long	get_mili(void)
{
	struct timeval	te;
	long long		mili;

	gettimeofday(&te, NULL);
	mili = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (mili);
}

void	ft_bzero(int *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i ++;
	}
}
