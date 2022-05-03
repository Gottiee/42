#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	while (s[i])
		i ++;
	write(fd, s, i);
	write(fd, "\n", 1);
}
