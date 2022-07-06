/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:13:32 by eedy              #+#    #+#             */
/*   Updated: 2022/07/06 20:01:57 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.a/ft_printf.h"
# include "libft.a/libft/libft.h"
# include "libft.a/libft/get_next_line.h"
# include <sys/wait.h>

# define ERROR_ARG 1

typedef struct s_cmd
{
	char	**cmd1;
	char	**cmd2;
	char	*com1;
	char	*com2;
	char	*file1;
	char	*file2;
}				t_cmd;

typedef struct s_fd
{
	int	p1[2];
	int	fd_file1;
	int	fd_file2;
}				t_fd;

/*          --- Fonctions principals ---     */

/*Fichier: main.c*/
int		main(int argc, char **argv, char **env);
char	*get_path(char **env, char *command);
char	*find_path(char *env, char *command);
void	first_dup(t_cmd *cmd, char **env);
void	second_dup(t_cmd *cmd, char **env, t_fd *fd);

/*          --- Fonctions qui gere la fin du program ---     */

/*Fichier: error.c*/
void	end_center(int event, ...);
void	error_arg(void);
void	free_malloc(t_cmd *cmd, int bolo);

#endif
