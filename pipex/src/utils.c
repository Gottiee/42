/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:02:55 by eedy              #+#    #+#             */
/*   Updated: 2022/07/20 12:27:04 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	init_struc(t_cmd *cmd, char **argv, char **env)
{
	cmd->cmd1 = ft_split(argv[2], ' ');
	cmd->cmd2 = ft_split(argv[3], ' ');
	cmd->com1 = get_path(env, cmd->cmd1[0]);
	cmd->com2 = get_path(env, cmd->cmd2[0]);
	if (!cmd->com1)
	{
		ft_printf("%s: No such file or directory\n", argv[2]);
	}
	if (!cmd->com2)
	{
		ft_printf("%s: No such file or directory\n", argv[3]);
		cmd->bolo_cmd2 = 0;
		return (1);
	}
	cmd->file1 = malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));
	cmd->file2 = malloc(sizeof(char) * (ft_strlen(argv[4]) + 1));
	if (!cmd->cmd1 || !cmd->cmd2 || !cmd->file1 || !cmd->file2)
	{
		ft_printf("Malloc error in main\n");
		free_malloc(cmd, 1);
		return (1);
	}
	return (0);
}

char	*get_path2(char *copy, char *command)
{
	char	*cmd;

	if (command[0] != '/')
	{
		copy[0] = '/';
		copy[1] = '\0';
	}
	else
		copy[0] = '\0';
	cmd = ft_strjoin(copy, command);
	if (!cmd)
		return (NULL);
	free(copy);
	return (cmd);
}
