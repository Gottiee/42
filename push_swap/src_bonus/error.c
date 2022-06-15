/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:18:22 by eedy              #+#    #+#             */
/*   Updated: 2022/06/15 11:24:10 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	end_center(int event, ...)
{
	va_list	ptr;		

	va_start(ptr, event);
	if (event == ERROR_ARG)
		error_arg(ptr);
}

void	error_arg(va_list ptr)
{
	int	*tab;

	tab = va_arg(ptr, int *);
	free(tab);
	ft_printf("Error\n");
	exit(1);
}
