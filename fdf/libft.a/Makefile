LIB = -L$(DIR_LIB) -lft

DIR_LIB = ./libft

NAME = libft.a

SRC =	ft_printf.c \
		ft_lst.c \
		ft_print_arg.c \
		ft_print_arg2.c \
		ft_print_str_ex.c
 
OBJ = $(SRC:.c=.o)	 

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ) 
		$(MAKE) bonus -C ./libft
		cp libft/libft.a ./$(NAME)
		ar -rcs $(NAME) $^

# %.o: %.c
#	$(CC) -c $(FLAGS) $(LIB) $^

 %.o: %.c
	$(CC) -c $(FLAGS) $^


bonus : all

clean :
	rm -f $(OBJ)
	$(MAKE) clean -C ./libft

fclean : clean
		rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re : fclean all

.PHONY: all bonus clean fclean re lib
