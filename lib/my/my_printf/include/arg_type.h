/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** arg_type
*/

#ifndef ARG_TYPE_H_
#define ARG_TYPE_H_

    #include "my_printf.h"
    #include <stdarg.h>

    typedef struct arg_type_s {
        char *sign;
        char *(*func)(va_list args, printf_data_t *data);
        int len;
    } arg_type_t;

    char *type_string(va_list args, printf_data_t *data);
    char *type_decimal(va_list args, printf_data_t *data);
    char *type_octal(va_list args, printf_data_t *data);
    char *type_binary(va_list args, printf_data_t *data);
    char *type_hexa(va_list args, printf_data_t *data);
    char *type_hexa_upper(va_list args, printf_data_t *data);
    char *type_unsigned_int(va_list args, printf_data_t *data);
    char *type_char(va_list args, printf_data_t *data);
    char *type_pointer(va_list args, printf_data_t *data);
    char *type_printable(va_list args, printf_data_t *data);
    char *type_modulo(va_list args, printf_data_t *data);

    static const arg_type_t ARG_TYPE_LIST[] = {
        {"s", &type_string, 1},
        {"d", &type_decimal, 1},
        {"i", &type_decimal, 1},
        {"o", &type_octal, 1},
        {"b", &type_binary, 1},
        {"x", &type_hexa, 1},
        {"X", &type_hexa_upper, 1},
        {"u", &type_unsigned_int, 1},
        {"c", &type_char, 1},
        {"p", &type_pointer, 1},
        {"S", &type_printable, 1},
        {"%", &type_modulo, 1},
        {(void *)NULL, (void *)NULL, 0}
    };

            /*{"S", &type_printable, 1},*/

#endif /* !ARG_TYPE_H */
