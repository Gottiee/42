int	ft_toupper(int c)
{
	if (c >= 97 || c <= 122)
		c -= 32;
	return (c);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
//	argv [1][0] = ft_toupper(argv[1][0]);
	int c = 'G';
	c = ft_toupper(c);
	printf("la lettre est %c\n", c);
	//printf("la lettre est %c\n", argv[1][0]);
}
