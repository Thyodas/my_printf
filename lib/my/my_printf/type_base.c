/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All functions to manage base type
*/

#include "include/my_printf.h"
#include "../my.h"
#include "include/flags.h"
#include <stdarg.h>

char *type_octal(va_list args, printf_data_t *data)
{
    unsigned int value = va_arg(args, unsigned int);
    char *result = my_strdup("");

    result = my_struint_base(value, result, "01234567");
    if (data->active_flags[F_POS_PREFIX])
        result = my_addchar(result, '0');
    my_revstr(result);
    return (result);
}

char *type_hexa(va_list args, printf_data_t *data)
{
    unsigned int value = va_arg(args, unsigned int);
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
    unsigned int value = va_arg(args, unsigned int);
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
    unsigned int value = va_arg(args, unsigned int);
    char *result = my_strdup("");

    result = my_struint_base(value, result, "01");
    my_revstr(result);
    return (result);
}

char *type_pointer(va_list args, printf_data_t *data)
{
    long value = va_arg(args, long);
    char *result = my_strdup("");

    result = my_strlong_base(value, result, "0123456789abcdef");
    result = my_addchar(result, 'x');
    result = my_addchar(result, '0');
    my_revstr(result);
    return (result);
}