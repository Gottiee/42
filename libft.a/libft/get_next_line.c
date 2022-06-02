/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:02:07 by eedy              #+#    #+#             */
/*   Updated: 2022/06/02 15:06:45 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	thks_nrm(size_t temp_i, unsigned char *tmp, size_t i, size_t n)
{
	(void)n;
	while (tmp[temp_i + i])
	{
		tmp[i] = tmp[temp_i + i];
		i ++;
	}
	while (i < n && tmp[i])
		tmp[i++] = 0;
	tmp[BUFFER_SIZE - 1] = 0;
}

void	*ft_memcpy_(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	source = (char *)src;
	dest = (char *)dst;
	i = 0;
	if (n != 0)
	{
		while (i < n && source[i])
		{
			dest[i] = source[i];
			i ++;
		}
		dest[i] = '\0';
	}
	return (dst);
}

void	ft_bzero_(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	if (!s)
		return ;
	i = 0;
	tmp = (unsigned char *)s;
	while (i < n && tmp[i])
	{
		if (tmp[i] == '\n')
			break ;
		tmp[i] = '\0';
		i ++;
	}
	if (tmp[i] == '\n')
	{
		thks_nrm(i + 1, tmp, 0, n);
	}
}

int	find_backslash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i ++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		buffer[BUFFER_SIZE + 1];
	t_list_gnl		*first;
	int				check_read;

	check_read = 1;
	if (BUFFER_SIZE < 1)
		return (NULL);
	first = init();
	line = NULL;
	while (check_read > 0 && !find_backslash(buffer))
	{
		if (buffer[0] != 0)
			add_list(first, buffer);
		else
		check_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (check_read > 0 || first -> next != NULL)
	{
		check_read = add_list(first, buffer);
		line = print_line(first, line);
	}
	del_list(first);
	return (line);
}
