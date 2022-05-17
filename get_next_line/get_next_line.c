/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:02:07 by eedy              #+#    #+#             */
/*   Updated: 2022/05/17 17:39:27 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char		*str;
	static int	fd_cp = 0;
	char		*buffer;
	int			check_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	fd_cp = fd;
	i = 0;
	check_read = 0;
	while (check_read != -1 && buffer[i] && buffer[i] != \n)
	{
		check_read = read(fd, buffer, 1);
		i ++;
	}
	/*l'idee c'est que tu recupere tout la chaine dans le buffer et tu prints le \0 a la fin. apres tu malloc str strlen de buffer et tu envoie la chaine de caractere buffer dans str et tu return
*/
}
