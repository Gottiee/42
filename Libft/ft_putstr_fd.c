#include <unistd.h>
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	write(fd, s, i);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int fd = open("test", O_CREAT | O_WRONLY);
	ft_putstr_fd("test", fd);
	close(fd);
}*/
