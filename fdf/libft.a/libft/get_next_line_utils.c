/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:46:38 by eedy              #+#    #+#             */
/*   Updated: 2022/06/02 15:08:36 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list_gnl	*init(void)
{
	t_list_gnl	*first;

	first = malloc(sizeof(t_list_gnl));
	if (!first)
		return (NULL);
	first -> next = NULL;
	return (first);
}

int	add_list(t_list_gnl *first, char *buffer)
{
	t_list_gnl	*new;
	t_list_gnl	*tmp;

	new = malloc(sizeof(t_list_gnl));
	if (!new)
		return (-1);
	tmp = first;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
	new -> next = NULL;
	ft_memcpy_(new -> str, buffer, BUFFER_SIZE + 1);
	ft_bzero_(buffer, BUFFER_SIZE + 1);
	return (1);
}

int	calcul_strlen(t_list_gnl *first)
{
	t_list_gnl	*tmp;
	int		str_len;
	int		i;

	str_len = 0;
	tmp = first;
	tmp = tmp -> next;
	while (tmp)
	{
		i = 0;
		while (tmp -> str[i])
		{
			if (tmp -> str[i] == '\n')
				return (i + 1 + str_len);
			i ++;
		}
		str_len += i;
		tmp = tmp -> next;
	}
	return (str_len);
}

char	*print_line(t_list_gnl *first, char *line)
{
	t_list_gnl	*tmp;
	int			line_size;
	int			i;
	int			j;

	i = 0;
	line_size = calcul_strlen(first);
	tmp = first;
	tmp = tmp -> next;
	line = malloc(sizeof(char) * (line_size + 1));
	if (!line)
		return (NULL);
	line[line_size] = '\0';
	while (tmp)
	{
		j = 0;
		while (tmp -> str[j] && tmp -> str[j] != '\n')
			line[i ++] = tmp -> str[j ++];
		line[i] = tmp -> str[j];
		tmp = tmp -> next;
	}
	return (line);
}

void	del_list(t_list_gnl *first)
{
	t_list_gnl	*tmp;

	while (first)
	{
		tmp = first;
		first = first -> next;
		free(tmp);
	}
}
