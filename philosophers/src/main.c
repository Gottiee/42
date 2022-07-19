/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:44:26 by eedy              #+#    #+#             */
/*   Updated: 2022/07/19 18:28:43 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	main(int argc, char **argv)
{
	pthread_t	*th;

	if (argc < 5 || argc > 6)		
		error(ARG_PRB);
	th = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
}
