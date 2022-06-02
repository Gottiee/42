/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:05:55 by eedy              #+#    #+#             */
/*   Updated: 2022/06/02 14:51:03 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	error_center(int error)
{
	if (error == ARGC_PRB || error == FD_PRB)
		error_no_free(error);
}

void	error_no_free(int error)
{
	if (error == ARGC_PRB) 
	{
		ft_printf("To many arguments or to few arguments.\nExit Programm.\n");
		exit(0);
	}
	if (error == FD_PRB)
	{
		ft_printf("No such file or directory.\nExit Programm.\n");
		exit(0);
	}
}
