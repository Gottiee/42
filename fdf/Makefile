NAME  = fdf

SRC_DIR = src/

SRC_FILES = main \
error \
map_parsing \
map_parsing_two \
algo \
handle \
mlx_fonction \
algo2 \
render

SRC =	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux -O0 -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C ./libft.a
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft.a -lft -o $(NAME)

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
