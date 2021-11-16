/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All functions to manage str type
*/

#include "include/my_printf.h"
#include "../my.h"
#include <stdarg.h>

char *type_string(va_list args, printf_data_t *data)
{
    return (va_arg(args, char *));
}

char *type_char(va_list args, printf_data_t *data)
{
    char value = va_arg(args, int);
    char *result = my_strdup("a");

    result[0] = value;
    return (result);
}

char *type_printable(va_list args, printf_data_t *data)
{
    return (va_arg(args, char *));
}