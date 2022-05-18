/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:52:06 by eedy              #+#    #+#             */
/*   Updated: 2022/05/18 16:20:32 by eedy             ###   ########.fr       */
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

typedef struct s_list
{
	char			str[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

/*			--- Fonction Principal---		*/

char	*get_next_line(int fd);

/*			--- Fonction qui gere les strings---		*/

void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strlen_remaster(char *str);
void	ft_bzero(void *s, size_t n);
int		find_backslash(char *str);
int		calcul_strlen(t_list *first);

/*			--- Fonction qui gere la liste chainee---		*/

t_list	*init(void);
char	*add_list(t_list *first, char *buffer);
char	*print_line(t_list *first, char *line);
void	del_list(t_list *first);


#endif
