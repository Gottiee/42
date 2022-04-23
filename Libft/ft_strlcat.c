#include <stdlib.h>

static size_t	ft_strlen(char *str)
{
	size_t	i;

	while (str[i])
		i ++;	
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	j = ft_strlen(dst);
	while(src[i] && size > i)
	{
		dst[j] = src[i];
		i ++;
		j ++;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char source[10] = "test";
	char dst[10] = "ok";
	ft_strlcat(dst, source, 10);
	printf("%s\n", dst);
}
