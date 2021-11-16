/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All functions to manage num type
*/

#include "include/my_printf.h"
#include "../my.h"
#include <stdarg.h>

char *type_decimal(va_list args, printf_data_t *data)
{
    int value = va_arg(args, int);
    char *result = my_strdup("");

    result = my_strint_base(value, result, "0123456789");
    result = my_addchar(result, get_sign_char(value < 0, data));
    my_revstr(result);
    return (result);
}

char *type_unsigned_int(va_list args, printf_data_t *data)
{
    unsigned int value = va_arg(args, unsigned int);
    char *result = my_strdup("");

    result = my_struint_base(value, result, "0123456789");
    my_revstr(result);
    return (result);
}