/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:51:09 by eedy              #+#    #+#             */
/*   Updated: 2022/10/03 13:21:22 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

void	print_upper_case(char *str)
{
	int i = -1;	
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	std::cout << str;
}

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 1)
	{
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	while (argv[++i])
	{
		print_upper_case(argv[i]);
		if (!argv[i + 1]) 
			std::cout << std::endl;
	}
	return (0);
}
