/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** arg_type
*/

#ifndef ARG_TYPE_H_
#define ARG_TYPE_H_

    #include "my_printf.h"

    typedef struct arg_type_s {
        char *sign;
        char *(*func)(void *, printf_data_t *data);
        int len;
    } arg_type_t;

    char *type_string(void *str, printf_data_t *data);
    /*char *type_printable(void *str, printf_data_t *data);
    char *type_decimal(void *value, printf_data_t *data);
    char *type_octal(void *value, printf_data_t *data);
    char *type_hexa(void *value, printf_data_t *data);
    char *type_hexa_upper(void *value, printf_data_t *data);
    char *type_character(void *c, printf_data_t *data);
    char *type_unsigned_int(void *value, printf_data_t *data);
    char *type_pointer(void *pointer, printf_data_t *data);*/

    static const arg_type_t ARG_TYPE_LIST[] = {
        {"s", &type_string, 1},
        {NULL, NULL, NULL}
    };

            /*{"S", &type_printable, 1},
        {"i", &type_decimal, 1},
        {"d", &type_decimal, 1},
        {"u", &type_unsigned_int, 1},
        {"x", &type_hexa, 1},
        {"X", &type_hexa_upper, 1},
        {"o", &type_octal, 1},
        {"p", &type_pointer, 1},*/

#endif /* !ARG_TYPE_H */
