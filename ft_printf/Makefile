LIB = -L$(DIR_LIB) -lft


DIR_LIB = ./libft

NAME = libftprintf.a

SRC = ft_lst.c \
	  ft_print_arg2.c \
	  ft_print_arg.c \
	  ft_printf.c 

OBJ = $(SRC:.c=.o)	 

CC = gcc

FLAGS = -Wall -Werror -Wextra 

all : lib $(NAME)

$(NAME): $(OBJ) 
		ar rc $(NAME) $^
		ranlib $(NAME)

lib : 
		$(MAKE) -C  ./libft
	
%.o: %.c
	$(CC) -c $(FLAGS) $(LIB) $^

bonus : all

clean :
	rm -f $(OBJ)
	$(MAKE) clean -C ./libft

fclean : clean
		rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re : fclean all

.PHONY: all bonus clean fclean re lib
