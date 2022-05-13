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

unsigned long long	long_convert(va_list ptr, int check)
{
	unsigned long long nbr;

	if (check ==)

}
int	ft_print_hexa_lowercase(unsigned long long nbr, int neg, int i)
{
	char	hexa[];


	if (neg == 1)
	{
		write(1, "-", 1);
		ft_print_hexa_lowercase(nbr, neg--, i);
	}
	if (nbr)

}
