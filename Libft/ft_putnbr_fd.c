#include <unistd.h>

char	*ft_putnbr(int n, int *i)
{
	char	*str;
	int		i;

	i = 0;
	if (n > 10)
		n /= 10;
	if (n > 0)
		ft_putnbr(n, i);
		
}
