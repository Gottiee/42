/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:02:07 by eedy              #+#    #+#             */
/*   Updated: 2022/05/19 13:27:50 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	source = (char *)src;
	dest = (char *)dst;
	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			dest[i] = source[i];
			i ++;
		}
	}
	return (dst);
}

int	 ft_strlen_remaster(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')	
			return (i + 1);
		i ++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			temp_i;
	size_t			i;
	unsigned char	*tmp;

	if (!s)
		return ;
	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		if (tmp[i] == '\n')
			break ;
		tmp[i] = 0;
		i ++;
	}
	if (tmp[i] == '\n')
	{
		temp_i = i + 1;	
		i = 0;
		while (tmp[temp_i + i])
		{
			tmp[i] = tmp[temp_i + i];
			i ++;
		}
		while (i < n)
		{
			tmp[i] = 0;
			i ++;
		}
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
	t_list			*first;
	int				check_read;

	check_read = 1;
	if (BUFFER_SIZE < 1)
		return (NULL);
	first = init();
	if (!first)
		return (NULL);
	while (check_read > 0 && !find_backslash(buffer))	
	{
		if (buffer[0] != 0)
			add_list(first, buffer);
		else
		check_read = read(fd, buffer, BUFFER_SIZE);
	}
	add_list(first, buffer);
	if (check_read == -1 || (check_read == 0 && first -> next == NULL))
		return (NULL);
	line = NULL;
	line = print_line(first, line);
	del_list(first);
	return (line);
}
