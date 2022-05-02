/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:40:59 by eedy              #+#    #+#             */
/*   Updated: 2022/05/02 15:41:33 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*print_0(char *str)
{
	str = (char *)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

void	print_n(char *str, unsigned int n, int *i)
{
	if (n > 0)
		print_n(str, n / 10, i);
	if (n > 0)
	{
		str[*i] = n % 10 + '0';
		(*i)++;
	}
}

char	*malloc_str(char *str, unsigned int n, int neg)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i ++;
	}
	if (neg == -1)
		i ++;
	str = (char *)malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	int				neg;
	unsigned int	uns_n;

	i = 0;
	neg = 1;
	str = NULL;
	if (n == 0)
	{
		str = print_0(str);
		return (str);
	}
	if (n < 0)
		neg = -1;
	uns_n = n * neg;
	str = malloc_str(str, uns_n, neg);
	if (neg == -1)
	{
		str[i] = '-';
		i ++;
	}
	print_n(str, uns_n, &i);
	return (str);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("%s\n", ft_itoa(0));
}*/
