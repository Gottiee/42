NAME  = philo

BONUS_NAME = philo_bonus

SRC_DIR = src/

BONUS_SRC_DIR = src_bonus/

SRC_FILES = main \
error \
utils \
struc

BONUS_SRC_FILES = 

SRC =	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

BONUS_SRC = $(addprefix $(BONUS_SRC_DIR), $(addsuffix .c, $(BONUS_SRC_FILES)))

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -pthread -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS)

clean :
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

bonus: $(BONUS_NAME)

re : fclean all


$(BONUS_NAME) : $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -o $(BONUS_NAME)


.PHONY: all clean fclean phony bonus re
