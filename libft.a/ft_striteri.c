/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:13:15 by eedy              #+#    #+#             */
/*   Updated: 2022/05/10 18:08:11 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (!s || !f)
		return ;
	while (i < s_len)
	{
		(f)(i, s);
		i ++;
		s ++;
	}
}
