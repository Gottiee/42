/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:02:55 by eedy              #+#    #+#             */
/*   Updated: 2022/07/08 15:04:22 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	init_struc(t_cmd *cmd, char **argv, char **env, int i)
{
	cmd->cmd1 = ft_split(argv[2 + i], ' ');
	cmd->cmd2 = ft_split(argv[3 + i], ' ');
	cmd->com1 = get_path(env, cmd->cmd1[0]);
	cmd->com2 = get_path(env, cmd->cmd2[0]);
	if (!cmd->com1 || !cmd->com2)
	{
		ft_printf("Unknow command\n");
		free_malloc(cmd, 0);
		return (1);
	}
	cmd->file1 = malloc(sizeof(char) * (ft_strlen(argv[1 + i]) + 1));
	cmd->file2 = malloc(sizeof(char) * (ft_strlen(argv[4 + i]) + 1));
	if (!cmd->cmd1 || !cmd->cmd2 || !cmd->file1 || !cmd->file2)
	{
		ft_printf("Malloc error in main\n");
		free_malloc(cmd, 1);
		return (1);
	}
	return (0);
}

int	cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i ++;
	}
	if (s2[i] == '\n')	
		return (1);
	return (0);
}

void	bonus_dup(t_cmd *cmd, char **env, t_fd *fd)
{
	char	buff[2];
	char	str[100000];
	int		i;
	int		k;
	(void)fd;

	i = 0;
	k = i;
	dup2(1, 0);
	while (!cmp(cmd->file1, str + k) || i == 0)
	{
		k = i;
		buff[0] = '\0';
		while (buff[0] != '\n')
		{
			read(0, buff, 1);
			str[i] = buff[0];
			i ++;
		}
	}
	write(1, &str, i);
	execve(cmd->com1, cmd->cmd1, env);
}
