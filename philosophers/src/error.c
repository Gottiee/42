/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:59:24 by eedy              #+#    #+#             */
/*   Updated: 2022/07/19 18:25:25 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	error(int err)
{
	if (err == ARG_PRB)
	{
		printf("Arg problem, to few or to many args !\n");
		exit(1);
	}
	if (err == ATOY)
	{
		printf("Can't accept negativ, null or float value\n");
		exit(1);
	}
}
