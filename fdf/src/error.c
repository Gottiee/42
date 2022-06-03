/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:05:55 by eedy              #+#    #+#             */
/*   Updated: 2022/06/03 13:12:43 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	error_center(int error, ...)
{
	va_list	ptr;

	va_start(ptr, error);
	if (error == ARGC_PRB || error == FD_PRB)
		error_no_free(error);
	if (error == MAP_PARSING_PRB)
		error_free_map_y(ptr);
	if (error == MAP_MALLOC_X_PRB)
		error_free_map_xy(ptr);
}

void	error_free_map_xy(va_list ptr)
{
	char	***map;
	int		i;

	map = va_arg(ptr, char ***);
	i = va_arg(ptr, int);
	while (i > -1)	
	{
		free(map[i]);
		i --;
	}
	free(map);
	ft_printf("Malloc error while mallocing x coordonne.\nExit Programm.\n");
	exit(EXIT_FAILURE);
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
		exit(EXIT_FAILURE);
	}
}

void	error_free_map_y(va_list ptr)
{
	int		line;
	char	***map;
	
	map = va_arg(ptr, char ***);
	line = va_arg(ptr, int);
	free(map);
	ft_printf("Map problem. Number of characters differ beetween line %d ", line);
	ft_printf("and line %d.\nExit Programm.\n", line -1);
	exit(EXIT_FAILURE);
}
