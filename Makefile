##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = lib/my/check_overflow.c \
	  lib/my/convert_base.c \
	  lib/my/my_compute_power_rec.c \
	  lib/my/my_compute_square_root.c \
	  lib/my/my_find_prime_sup.c \
	  lib/my/my_getnbr_base.c \
	  lib/my/my_getnbr.c \
	  lib/my/my_is_prime.c \
	  lib/my/my_isneg.c \
	  lib/my/my_put_nbr.c \
	  lib/my/my_putchar.c \
	  lib/my/my_putnbr_base.c \
	  lib/my/my_putstr.c \
	  lib/my/my_revstr.c \
	  lib/my/my_show_word_array.c \
	  lib/my/my_showmem.c \
	  lib/my/my_showstr.c \
	  lib/my/my_sort_int_array.c \
	  lib/my/my_str_isalpha.c \
	  lib/my/my_str_islower.c \
	  lib/my/my_str_isnum.c \
	  lib/my/my_str_isprintable.c \
	  lib/my/my_str_isupper.c \
	  lib/my/my_str_to_word_array.c \
	  lib/my/my_strcapitalize.c \
	  lib/my/my_strcat.c \
	  lib/my/my_strdup.c \
	  lib/my/my_strlen.c \
	  lib/my/my_strlowcase.c \
	  lib/my/my_strncat.c \
	  lib/my/my_strncmp.c \
	  lib/my/my_strcmp.c \
	  lib/my/my_strncpy.c \
	  lib/my/my_strstr.c \
	  lib/my/my_strupcase.c \
	  lib/my/my_swap.c \
	  lib/my/my_strcpy.c \
	  lib/my/power.c \
	  lib/my/swap_endian_color.c \
	  lib/my/get_color.c \
	  lib/my/my_printf/my_printf.c \
	  lib/my/my_printf/struct_utils.c \
	  lib/my/my_printf/type_base.c \
	  lib/my/my_printf/type_char.c \
	  lib/my/my_printf/type_num.c \
	  lib/my/my_printf/type_utils.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
		 ar rc $(NAME) $(OBJ)
		 cp lib/my/my.h include/my.h
		 cp $(NAME) lib/$(NAME)
		 cp $(NAME) lib/my/$(NAME)

clean:
	   rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean $(NAME)
