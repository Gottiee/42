/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:21:25 by eedy              #+#    #+#             */
/*   Updated: 2022/05/11 11:21:30 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	a = 10;
	ft_printf("ma fonction: %d\n", a);
	printf("la fontion original: %d\n", a);
}
