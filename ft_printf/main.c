/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:21:25 by eedy              #+#    #+#             */
/*   Updated: 2022/05/17 13:13:26 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int c = '0';
	printf("ma fonction renvoie la valeur %d\n", ft_printf(" %x ", 45));
	write(1, "\n", 1);
	printf("la fonction orignal renvoie la valeur %d\n", printf(" %x ", 45));
	write(1, "\n", 1);
}
