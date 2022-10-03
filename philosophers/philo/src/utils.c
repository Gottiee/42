/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:01 by eedy              #+#    #+#             */
/*   Updated: 2022/10/03 18:07:57 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	think_expended(void)
{
	t_philo	*philo;

	philo = get_struct();
	if ((philo->time_to_die - \
	(philo->time_to_eat + philo->time_to_sleep) - 100) * 1000 > 0)
		usleep((philo->time_to_die - \
	(philo->time_to_eat + philo->time_to_sleep) - 100) * 1000);
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
