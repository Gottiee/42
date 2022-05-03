#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	while (str[i])
		i ++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*new_s;
	int		s_leng;
	int		i;

	i = 0;
	len = ft_strlen((char *)s);
	if (!(new_s = malloc(sizeof(char) * len + 1)))
	s_new[len + 1] ='\0';
	while (s[i])
	{
		new_s[i] = (f)(i, s[i]);
		i ++;
	}
	return (new_s);
}
