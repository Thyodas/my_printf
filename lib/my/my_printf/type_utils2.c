/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All utils for type funcs
*/

#include "include/my_printf.h"
#include "../my.h"
#include "include/flags.h"

char *my_addchar(char *src, char c);
char get_sign_char(int is_neg, printf_data_t *data);

char *my_strshort_base(short nbr, char *str, char const *base, int precision)
{
    int len_base = my_strlen(base);
    short new_nbr = nbr;
    short remainder = 0;
    char *str_ptr = str;

    if (nbr == 0 && precision == -1)
        return (my_addchar(str_ptr, base[0]));
    while (new_nbr != 0 || precision > 0) {
        remainder = ABS(new_nbr % len_base);
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
        precision--;
    }
    return (str_ptr);
}

char *my_strushort_base(unsigned short nbr, char *str, char const *base, int precision)
{
    int len_base = my_strlen(base);
    unsigned short new_nbr = nbr;
    unsigned short remainder = 0;
    char *str_ptr = str;

    if (nbr == 0 && precision == -1)
        return (my_addchar(str_ptr, base[0]));
    while (new_nbr != 0 || precision > 0) {
        remainder = new_nbr % len_base;
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
        precision--;
    }
    return (str_ptr);
}
