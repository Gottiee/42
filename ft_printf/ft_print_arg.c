int	ft_putchar(va_list ptr)
{
	char	c;

	c = va_arg(ptr, char);
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(va_list ptr)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	str = va_arg(ptr, char *)
	while (str[i])
	{
		write(1, str + i, 1);
		i ++;
		count ++;
	}
	return (count);
}

int	ft_print_hexa_lowercase(va_list	ptr)
