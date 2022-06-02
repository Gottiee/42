/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:52:06 by eedy              #+#    #+#             */
/*   Updated: 2022/06/02 15:23:32 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>

# define BUFFER_SIZE 100

typedef struct s_list_gnl
{
	char				str[BUFFER_SIZE + 1];
	struct s_list_gnl	*next;
}	t_list_gnl;

/*			--- Fonction Principal---		*/

char		*get_next_line(int fd);

/*			--- Fonction qui gere les strings---		*/

void		*ft_memcpy_(void *dst, const void *src, size_t n);
void		ft_bzero_(void *s, size_t n);
int			find_backslash(char *str);
int			calcul_strlen(t_list_gnl *first);
void		thks_nrm(size_t temp_i, unsigned char *tmp, size_t i, size_t n);

/*			--- Fonction qui gere la liste chainee---		*/

t_list_gnl	*init(void);
int			add_list(t_list_gnl *first, char *buffer);
char		*print_line(t_list_gnl *first, char *line);
void		del_list(t_list_gnl *first);

#endif
