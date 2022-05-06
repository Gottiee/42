/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <gottiedev@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:13:05 by eedy              #+#    #+#             */
/*   Updated: 2022/05/06 19:20:43 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(unsigned int n, int fd)
{
	int	c;

	c = 0;
	if (n > 9)
		ft_putnbr(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int				neg;
	unsigned int	u_n;

	if (fd == -1)
		return ;
	neg = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		neg = -1;
	}
	u_n = n * neg;
	ft_putnbr(u_n, fd);
}

/*#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int fd = open("test", O_CREAT | O_WRONLY);
	if (fd == -1)
	{
		printf("rater");
		return (0);
	}
	ft_putnbr_fd(-2147483648, fd);
	close(fd);
}*/
