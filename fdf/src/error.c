/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:05:55 by eedy              #+#    #+#             */
/*   Updated: 2022/06/02 13:22:51 by eedy             ###   ########.fr       */
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
		perror("To many argument");
		exit(0);
	}
	if (error == FD_PRB)
	{
		perror("File error")
		exit(0);
	}
}
