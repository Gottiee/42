#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

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

void		init_bolo(t_bolo *bolo);
int			check_flags(const char *str, int *i, int str_len, t_bolo *bolo);

/*			--- Fonction qui gere les argument variadiques ---			*/


int			ft_putchar(va_list ptr);
int			long_convert(va_list ptr, int check, t_bolo *bolo);
int			ft_putstr(va_list ptr);
int			ft_print_hexa_lowercase(unsigned long long nbr, int *count);
int			ft_print_hexa_uppercase(unsigned long long nbr, int *count);
int 		ft_check_unsigned(va_list ptr);
int			ft_checknbr(va_list ptr, t_bolo *bolo);
int			ft_putnbr(unsigned int nbr, int *count);
int			long_convert_ptr(va_list ptr);
#endif
