/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:18:21 by eedy              #+#    #+#             */
/*   Updated: 2022/07/08 13:56:48 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_cmd	cmd;
	int		i;

	i = 0;
	if (argc < 5)
		end_center(ERROR_ARG);
	if (argc == 6)
		i = 1;
	if (init_struc(&cmd, argv, env, i))
		return (1);
	ft_strlcpy(cmd.file1, argv[1 + i], ft_strlen(argv[1]) + 1);
	ft_strlcpy(cmd.file2, argv[4 + i], ft_strlen(argv[4]) + 1);
	first_dup(&cmd, env, argc);
	free_malloc(&cmd, 1);
}

char	*get_path(char **env, char *command)
{
	int		i;
	int		max;
	char	*cmd;

	i = 0;
	max = 0;
	cmd = malloc(sizeof(char) * 1 + sizeof(command));
	if (!cmd)
		return (NULL);
	cmd[0] = '/';
	cmd[1] = '\0';
	ft_strlcat(cmd, command, ft_strlen(command) + 2);
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 4))
			max = i;
		i ++;
	}
	if (max == 0)
		return (NULL);
	return (find_path(env[max] + 5, cmd));
}

char	*find_path(char *env, char *command)
{
	char	**all_path;
	char	*path;
	int		i;
	int		malloc_size;

	i = 0;
	all_path = ft_split(env, ':');
	while (all_path[i])
	{
		malloc_size = ft_strlen(all_path[i]) + ft_strlen(command);
		path = malloc(sizeof(char) * (malloc_size + 1));
		ft_strlcpy(path, all_path[i], ft_strlen(all_path[i]) + 1);
		ft_strlcat(path, command, malloc_size + 1);
		if (access(path, X_OK) == 0)
			return (path);
		i ++;
		free(path);
	}
	return (NULL);
}

void	first_dup(t_cmd *cmd, char **env, int argc)
{
	t_fd	fd;	
	int		id;

	pipe(fd.p1);
	id = fork();
	if (id == 0)
	{
		dup2(fd.p1[1], 1);
		if (argc == 6)
			bonus_dup(cmd, env, &fd);
		else
		{
			close(fd.p1[0]);
			fd.fd_file1 = open(cmd->file1, O_RDONLY);
			if (fd.fd_file1 == -1)
			{
				close(fd.p1[1]);
				perror("error ");
				return ;
			}
			dup2(fd.fd_file1, 0);
		}
		execve(cmd->com1, cmd->cmd1, env);
		close(fd.p1[1]);
	}
	else
	{
		wait(0);
		second_dup(cmd, env, &fd);
	}
}

void	second_dup(t_cmd *cmd, char **env, t_fd *fd)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		fd->fd_file2 = open(cmd->file2, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		close(fd->p1[1]);
		if (fd->fd_file2 == -1)
		{
			close(fd->p1[0]);
			perror("error ");
			return ;
		}
		dup2(fd->fd_file2, 1);
		dup2(fd->p1[0], 0);
		execve(cmd->com2, cmd->cmd2, env);
		close(fd->p1[0]);
	}
}
