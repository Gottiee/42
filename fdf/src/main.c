/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:03:29 by eedy              #+#    #+#             */
/*   Updated: 2022/06/09 14:38:57 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_map	***map;

	if (argc != 2)
		error_center(ARGC_PRB);
	map = map_parsing(argv[1]);
	mlx_center(map);
	error_center(FREE_MAP, map);
}
