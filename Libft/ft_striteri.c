void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	while (s[i])
	{
		s[i] = (f)(i, s);
		i ++;
	}
}
