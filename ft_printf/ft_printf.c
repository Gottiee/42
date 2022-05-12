/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:21:32 by eedy              #+#    #+#             */
/*   Updated: 2022/05/12 13:06:30 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	distrib(int check, va_list ptr)
{
	
}

int	check_str(char c)
{
	if (c == 'c')	
		return (1);
	if (c == 's')	
		return (2);
	if (c == 'p')	
		return (3);
	if (c == 'd' || c == 'i')	
		return (4);
	if (c == 'u')	
		return (5);
	if (c == 'x')	
		return (6)
	if (c == 'X')	
		return (7)
	if (c == '%')	
		return (8);
	else
		return (0);
}

int	print_str(const char *str, int *i, va_list ptr, t_bolo *bolo)
{
	int	count;
	int	check;
	int	str_len;

	str_len = ft_strlen(str);
	count = 0;
	while (*i < str_len)
	{
		if (i + 1 < str_len && str[i] == '%')	
		{
			(*i)++;
			check = check_flags(str, i, str_len)
			if (check != 0 *i >= str_len)
				return (0);
			check = check_str(str[i])
			if (check == 0)
				return (0);
			count += distrib(check, ptr);
			/*distrib regarde le chiffre et renvoi vers les variable
			qui traite les bons paramettres*/
		}
		write(1, str + i, 1);
		i ++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list ptr;
	t_bolo	*bolo;	
	int		count;
	int		i;

	i = 0;
	va_start(ptr, str);
	init_bolo(bolo);
	print_str(str, &i, ptr, bolo);
	bolo = malloc(sizeof(t_bolo));
	free(bolo);
}
