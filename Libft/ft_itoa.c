#include <stdlib.h>

void	print_n(char *str, int n, int *i)
{
	if (nb > 0)
		print_n(str, n /10, &i);
	if (n > 0)
	{
		str[*i] = n  
	}
	
}

char	*malloc_str(char *str, int n)
{
	int	i;

	i = 0;
	while(n)
	{
		n /10;
		i ++;
	}
	str = (char *)malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	return (str);
}

char	ft_itoa(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc_str(str, n);
	print_n(str, n, &i);
}
