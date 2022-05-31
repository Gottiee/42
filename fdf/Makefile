NAME  = fdf

SRC = main.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra  -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
