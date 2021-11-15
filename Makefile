##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = main.c \
	  utils.c \
	  main_printf.c \
	  type_funcs.c

OBJ = $(SRC:.c=.o)

NAME = a.out

INCLUDE = include

LIB = lib/my

CFLAGS = -I$(INCLUDE) -Wall -Wextra -g

all: $(NAME)

make_lib:
		  make -C $(LIB)

$(NAME): make_lib $(OBJ)
		 gcc -g -o $(NAME) $(OBJ) -L$(LIB) -lmy
		 rm -f $(OBJ)

clean:
	   make clean -C $(LIB)
	   rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: fclean all debug re clean make_lib $(NAME)
