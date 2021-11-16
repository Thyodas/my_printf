/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All functions to manage str type
*/

#include "my_printf.h"
#include "my.h"
#include "flags.h"
#include <stdarg.h>

char *my_addchar(char *src, char c)
{
    int len = my_strlen(src);
    int i = 0;
    char *dest = malloc(sizeof(char) * (len + 2));

    for (; src[i] != '\0' ; ++i)
        dest[i] = src[i];
    dest[i] = c;
    dest[i + 1] = '\0';
    //free(src);
    return dest;
}

char *my_strint_base(int nbr, char *str, char const *base)
{
    int len_base = my_strlen(base);
    int new_nbr = nbr;
    int remainder = 0;
    char *str_ptr = str;
    char *to_free = NULL;

    if (nbr == 0)
        return (my_addchar(str, '0'));
    while (new_nbr != 0) {
        remainder = ABS(new_nbr % len_base);
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
    }
    to_free = str_ptr;
    //free(to_free);
    return (str_ptr);
}

char *my_struint_base(unsigned int nbr, char *str, char const *base)
{
    int len_base = my_strlen(base);
    unsigned int new_nbr = nbr;
    unsigned int remainder = 0;
    char *str_ptr = str;
    char *to_free = NULL;

    if (nbr == 0)
        return (my_addchar(str, '0'));
    while (new_nbr != 0) {
        remainder = ABS(new_nbr % len_base);
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
    }
    to_free = str_ptr;
    //free(to_free);
    return (str_ptr);
}

char *type_string(va_list args, printf_data_t *data)
{
    return (va_arg(args, char *));
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
}

char *type_decimal(va_list args, printf_data_t *data)
{
    int value = va_arg(args, int);
    char *result = my_strdup("");

    result = my_strint_base(value, result, "0123456789");
    result = my_addchar(result, get_sign_char(value < 0, data));
    my_revstr(result);
    return (result);
}

char *type_octal(va_list args, printf_data_t *data)
{
    int value = va_arg(args, int);
    char *result = my_strdup("");

    result = my_struint_base(value, result, "01234567");
    if (data->active_flags[F_POS_PREFIX])
        result = my_addchar(result, '0');
    my_revstr(result);
    return (result);
}

char *type_hexa(va_list args, printf_data_t *data)
{
    int value = va_arg(args, int);
    char *result = my_strdup("");

    result = my_struint_base(value, result, "0123456789abcdef");
    if (data->active_flags[F_POS_PREFIX]) {
        result = my_addchar(result, 'x');
        result = my_addchar(result, '0');
    }
    my_revstr(result);
    return (result);
}

char *type_hexa_upper(va_list args, printf_data_t *data)
{
    int value = va_arg(args, int);
    char *result = my_strdup("");

    result = my_struint_base(value, result, "0123456789ABCDEF");
    if (data->active_flags[F_POS_PREFIX]) {
        result = my_addchar(result, 'X');
        result = my_addchar(result, '0');
    }
    my_revstr(result);
    return (result);
}

char *type_binary(va_list args, printf_data_t *data)
{
    int value = va_arg(args, int);
    char *result = my_strdup("");

    result = my_struint_base(value, result, "01");
    my_revstr(result);
    return (result);
}