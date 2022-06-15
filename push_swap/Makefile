NAME  = push_swap

BONUS_NAME = checker

SRC_DIR = src/

BONUS_SRC_DIR = src_bonus/

SRC_FILES = main \
arg_parsing \
error \
instruction \
instruction_2 \
instruction_3

BONUS_SRC_FILES = main_bonus \
arg_parsing \
error \
instruction \
instruction_2 \
instruction_3 \
check_buffer

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

fclean_all: fclean
	$(MAKE) fclean -C ./libft.a

re_lib:
	$(MAKE) re -C ./libft.a

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJ)
	$(MAKE) -C ./libft.a
	$(CC) $(BONUS_OBJ) -Llibft.a -lft -o $(BONUS_NAME)


.PHONY: all clean fclean_all re_lib return phony bonus
