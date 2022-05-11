/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:21:32 by eedy              #+#    #+#             */
/*   Updated: 2022/05/11 18:16:16 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	print_str(const char *str, int *i, int str_len)
{
	int	count;

	count = 0;
	while (*i < str_len)
	{
		if (i + 1 < str_len && str[i] == '%')	
		{
			check_flags(str, i, str_len)
			count += distrib(check_str(str[i]));
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
	int		i; 
	int		type;
	int		str_len;

	/* i pour avancer dans la chaine de caractere argument l'un apres 
	l'autre sans revenir au debut
	type pour que la fonction check str return des chiffes de 0 a ... pour dire
	le type de l'argument traite*/
	str_len = ft_strlen(str);
	type = 0;
	while (i < str_len)
	{
		type = check_str(str, &i, str_len);
		if (type)
		{
			
		}
	}

}
