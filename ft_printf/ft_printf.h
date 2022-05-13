#ifndef FT_PRINTF_H
#define FT_PRINTF_H


# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_bolo
{
	int	hastag;
	int	space;
	int	plus;
}				t_bolo;

/*			--- Fonction qui gere la string envoyee ---		*/

int			distrib(int check, va_list ptr, t_bolo *bolo);
int			check_str(char c);
int			print_str(const char *str, int *i, va_list ptr, t_bolo *bolo);
int			ft_printf(const char *str, ...);

/*			--- Fonction qui gere la structure ---			*/


#endif
