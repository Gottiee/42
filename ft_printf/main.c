#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	a = 10;
	ft_printf("ma fonction: %d\n", a);
	printf("la fontion original: %d\n", a);
}
