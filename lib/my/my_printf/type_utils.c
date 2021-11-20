/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All utils for type funcs
*/

#include "include/my_printf.h"
#include "../my.h"
#include "include/flags.h"

char *my_addchar(char *src, char c)
{
    int len = my_strlen(src);
    int i = 0;
    char *dest = malloc(sizeof(char) * (len + 2));

    for (; src[i] != '\0' ; ++i)
        dest[i] = src[i];
    dest[i] = c;
    dest[i + 1] = '\0';
    return dest;
}

char *my_strint_base(int nbr, char *str, char const *base, int precision)
{
    int len_base = my_strlen(base);
    int new_nbr = nbr;
    int remainder = 0;
    char *str_ptr = str;

    if (nbr == 0)
        return (my_addchar(str, '0'));
    while (new_nbr != 0 || precision > 0) {
        remainder = ABS(new_nbr % len_base);
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
        precision--;
    }
    return (str_ptr);
}

char *my_struint_base(unsigned int nbr, char *str, char const *base,
int precision)
{
    int len_base = my_strlen(base);
    unsigned int new_nbr = nbr;
    unsigned int remainder = 0;
    char *str_ptr = str;

    if (nbr == 0)
        return (my_addchar(str, '0'));
    while (new_nbr != 0 || precision > 0) {
        remainder = new_nbr % len_base;
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
        precision--;
    }
    return (str_ptr);
}

char *my_strlong_base(long nbr, char *str, char const *base, int precision)
{
    int len_base = my_strlen(base);
    long new_nbr = nbr;
    long remainder = 0;
    char *str_ptr = str;

    if (nbr == 0)
        return (my_addchar(str, '0'));
    while (new_nbr != 0 || precision > 0) {
        remainder = ABS(new_nbr % len_base);
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
        precision--;
    }
    return (str_ptr);
}

char *my_strulong_base(unsigned long nbr, char *str, char const *base,
int precision)
{
    int len_base = my_strlen(base);
    unsigned long new_nbr = nbr;
    unsigned long remainder = 0;
    char *str_ptr = str;

    if (nbr == 0)
        return (my_addchar(str, '0'));
    while (new_nbr != 0 || precision > 0) {
        remainder = new_nbr % len_base;
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
        precision--;
    }
    return (str_ptr);
}

char get_sign_char(int is_neg, printf_data_t *data)
{
    if (is_neg)
        return('-');
    else {
        if (data->active_flags[F_POS_SHOW_POSITIVE])
            return ('+');
        if (data->active_flags[F_POS_BLANK_POSITIVE])
            return (' ');
    }
    return ('\0');
}
