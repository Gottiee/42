/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:02:55 by eedy              #+#    #+#             */
/*   Updated: 2022/07/11 14:25:25 by eedy             ###   ########.fr       */
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

	i = 0;
	k = i;
	while (i == 0 || !cmp(cmd->file1, str + k))
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
	fd->fd_tmp = open("tmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	write(fd->fd_tmp, &str, k);
	close(fd->fd_tmp);
	open("tmp", O_RDONLY);
	dup2(fd->fd_tmp, 0);
	execve(cmd->com1, cmd->cmd1, env);
}

int	first_fork2(t_cmd *cmd, t_fd *fd)
{
	close(fd->p1[0]);
	fd->fd_file1 = open(cmd->file1, O_RDONLY);
	if (fd->fd_file1 == -1)
	{
		close(fd->p1[1]);
		perror("error ");
		return (0);
	}
	dup2(fd->fd_file1, 0);
	return (1);
}

int	verif_arg(char *arg)
{
	if (arg[0] == 'h' && arg[1] == 'e' && arg[2] == 'r'
		&& arg[3] == 'e' && arg[4] == '_' && arg[5] == 'd'
		&& arg[6] == 'o' && arg[7] == 'c')
		return (1);
	else
		return (0);
}
