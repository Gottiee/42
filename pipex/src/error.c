/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:18:22 by eedy              #+#    #+#             */
/*   Updated: 2022/07/11 14:00:25 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	end_center(int event, ...)
{
	va_list	ptr;		

	va_start(ptr, event);
	if (event == ERROR_ARG)
		error_arg();
	va_end(ptr);
}

void	error_arg(void)
{
	ft_printf("Argument Error\n");
	exit(1);
}

void	free_malloc(t_cmd *cmd, int bolo)
{
	int	i;	

	i = 0;
	while (cmd->cmd1[i])
	{
		free(cmd->cmd1[i]);
		i ++;
	}
	free(cmd->cmd1);
	i = 0;
	while (cmd->cmd2[i])
	{
		free(cmd->cmd2[i]);
		i ++;
	}
	free(cmd->cmd2);
	if (bolo == 1)
	{
		free(cmd->file1);
		free(cmd->file2);
	}
	free(cmd->com1);
	free(cmd->com2);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i ++;
	}
	free(path);
}
