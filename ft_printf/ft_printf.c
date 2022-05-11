/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:21:32 by eedy              #+#    #+#             */
/*   Updated: 2022/05/11 11:38:48 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	ft_printf(const char *str, ...)
{
	va_list ptr;
	int		i; 
	int		arg;
	/* i pour avancer dans la chaine de caractere argument l'un apres 
	l'autre sans revenir au debut*/

	arg = check_str(str, &i);
}
