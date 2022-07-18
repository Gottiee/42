/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:18:21 by eedy              #+#    #+#             */
/*   Updated: 2022/07/18 19:13:36 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_cmd	cmd;

	if (argc != 5)
		end_center(ERROR_ARG);
	cmd.bolo_cmd1 = 1;
	cmd.bolo_cmd2 = 1;
	if (init_struc(&cmd, argv, env))
	{
		free_malloc(&cmd, 0);
		return (1);
	}
	ft_strlcpy(cmd.file1, argv[1], ft_strlen(argv[1]) + 1);
	ft_strlcpy(cmd.file2, argv[4], ft_strlen(argv[4]) + 1);
	first_dup(&cmd, env);
	free_malloc(&cmd, 1);
}

char	*get_path(char **env, char *command, t_cmd *struc)
{
	int		i;
	int		max;
	char	*cmd;
	char	**path;
	(void)path;
	(void)struc;

	i = 0;
	max = 0;
	cmd = malloc(sizeof(char) * (1 + sizeof(command)));
	if (!cmd)
		return (NULL);
	if (command[0] != '/')
	{
		cmd[0] = '/';
		cmd[1] = '\0';
	}
	else
		cmd[0] = '\0';
	ft_strlcat(cmd, command, ft_strlen(command) + 2);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 4))
			max = i;
		i ++;
	}
	if (max == 0)
	{
		free(cmd);
		printf("merci shelckok\n");
		return (NULL);
	}
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
		{
			free_path(all_path);
			free(command);
			return (path);
		}
		i ++;
		free(path);
	}
	free_path(all_path);
	free(command);
	return (NULL);
}

void	first_dup(t_cmd *cmd, char **env)
{
	t_fd	fd;	
	int		id;

	pipe(fd.p1);
	id = fork();
	if (id == 0 && cmd->bolo_cmd1 == 1)
	{
		fd.fd_file1 = open(cmd->file1, O_RDONLY);
		close(fd.p1[0]);
		if (fd.fd_file1 == -1)
		{
			close(fd.p1[1]);
			perror("error ");
			return ;
		}
		dup2(fd.fd_file1, 0);
		dup2(fd.p1[1], 1);
		printf("ok\n");
		execve(cmd->com1, cmd->cmd1, env);
		close(fd.p1[1]);
	}
	else
	{
	/*wait(0);*/	
		second_dup(cmd, env, &fd);
	}
}

void	second_dup(t_cmd *cmd, char **env, t_fd *fd)
{
	int	id;

	if (cmd->bolo_cmd2 == 1)
		id = fork();
	if (cmd->bolo_cmd2 == 1 && id == 0)
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
	else
	{
		close(fd->p1[0]);
		close(fd->p1[1]);
		wait(0);	
	}
}
