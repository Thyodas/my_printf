/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All functions to manage num type
*/

#include "include/my_printf.h"
#include "../my.h"
#include <stdarg.h>

char *type_short(va_list args, printf_data_t *data)
{
    short value = va_arg(args, short);
    char *result = my_strdup("");
    char sign = get_sign_char(value < 0, data);

    data->is_nb = 1;
    result = my_strshort_base(value, result, "0123456789", data->precision);
    result = my_addchar(result, sign);
    data->prefix_len = sign != '\0';
    my_revstr(result);
    return (result);
}

char *type_unsigned_short(va_list args, printf_data_t *data)
{
    unsigned short value = va_arg(args, unsigned short);
    char *result = my_strdup("");

    data->is_nb = 1;
    result = my_strushort_base(value, result, "0123456789", data->precision);
    my_revstr(result);
    return (result);
}
