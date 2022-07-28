/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:59:24 by eedy              #+#    #+#             */
/*   Updated: 2022/07/28 17:04:54 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	error(int err)
{
	t_philo	*philo;

	philo = get_struct();
	if (err == ARG_PRB)
	{
		printf("Arg problem, to few or to many args !\n");
		exit(1);
	}
	if (err == ATOY)
	{
		printf("Can't accept negativ, null or float value.\n");
		free(philo->fork);
		free(philo->eat);
		free(philo->dead);
		exit(1);
	}
	if (err == ATOY_INTEGER)
	{
		printf("Out of the integer range.\n");
		free(philo->fork);
		free(philo->eat);
		free(philo->dead);
		exit(1);
	}
}
