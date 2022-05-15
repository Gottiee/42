DIR_LIB = ./libft/

NAME = libftprintf.a

SRC = ft_lst.c \
	  ft_print_arg2.c \
	  ft_print_arg.c \
	  ft_printf.c \

OBJ = &(SRC:.c=.o)	 

CC = gcc

FLAGS = -Wall -Werror -Wextra -L$(DIR_LIB)

all : lib $(NAME)

lib : 
	cd libft
	make bonus
	mv libft.a ../.
	cd ../

$(NAME): $(OBJ) 
		ar rc $(NAME) $^
		rnalib $(NAME)
%.o: %.c
	$(CC) -c $(FLAGS) $^

bonus : all

clean :
	rm -f $(OBJ)
	cd libft
	make clean
	cd ../

fclean : clean
		rm -f $(NAME)
	cd libft
	make fclean
	cd ../

re : flcean all
	rm -f $(OBJ) $(BONUS_OBJ)

.PHONY: all bonus clean fclean re lib
