NAME  = pipex

BONUS_NAME = pipex_bonus

SRC_DIR = src/

BONUS_SRC_DIR = src_bonus/

SRC_FILES = main \
error \
utils

BONUS_SRC_FILES = main \
error \
utils \
utils2

SRC =	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

BONUS_SRC = $(addprefix $(BONUS_SRC_DIR), $(addsuffix .c, $(BONUS_SRC_FILES)))

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

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

fclean_lib: fclean
	$(MAKE) fclean -C ./libft.a

re_lib:
	$(MAKE) re -C ./libft.a
	$(MAKE) clean -C ./libft.a

fclean : clean
	rm -f $(NAME)

clean_all: clean
	rm -f $(BONUS_OBJ)

fclean_all: clean_all fclean_lib
	rm -f $(BONUS_NAME)
	rm -f $(NAME)

bonus: all $(BONUS_NAME)

re : fclean_all all bonus


$(BONUS_NAME) : $(BONUS_OBJ)
	$(MAKE) -C ./libft.a
	$(CC) $(BONUS_OBJ) -Llibft.a -lft -o $(BONUS_NAME)


.PHONY: all clean fclean_all re_lib return phony bonus
