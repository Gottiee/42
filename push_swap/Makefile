NAME  = push_swap

SRC_DIR = src/

SRC_FILES = main \
arg_parsing \
error

SRC =	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C ./libft.a
	$(CC) $(OBJ) -Llibft.a -lft -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS)

clean :
	rm -f $(OBJ)

fclean_all: fclean
	$(MAKE) fclean -C ./libft.a

re_lib:
	$(MAKE) re -C ./libft.a

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean_all re_lib return phony
