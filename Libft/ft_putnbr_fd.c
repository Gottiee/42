#include <unistd.h>

void	ft_putnbr(int n, int fd)
{
	int	c;

	c = 0;
	if (n > 9)
		ft_putnbr(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}

#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int fd = open("test", O_CREAT || O_WRONLY);
	ft_putnbr_fd(23, fd);
	close(fd);
}
