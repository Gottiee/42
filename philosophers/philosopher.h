/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:51:47 by eedy              #+#    #+#             */
/*   Updated: 2022/07/19 18:27:54 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define ARG_PRB 1
# define ATOY 2

/*          --- Fonctions principals ---     */

/*Fichier: main.c*/
int		main(int argc, char **argv);

/*          --- Fonctions qui gere les erreurs ---     */

/*Fichier: error.c*/
void	error(int err);

/*          --- Fonctions utils---     */

/*Fichier: utils.c*/
long	ft_atoi(const char *str);
#endif
