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
        char sign;
        int (*func)(void *, printf_data_t *data);
    } arg_type_t;

    int arg_string(void *str, printf_data_t *data);
    int arg_printable(void *str, printf_data_t *data);
    int arg_decimal(void *value, printf_data_t *data);
    int arg_octal(void *value, printf_data_t *data);
    int arg_hexa(void *value, printf_data_t *data);
    int arg_hexa_upper(void *value, printf_data_t *data);
    int arg_character(void *c, printf_data_t *data);
    int arg_unsigned_int(void *value, printf_data_t *data);
    int arg_pointer(void *pointer, printf_data_t *data);

    const arg_type_t ARG_TYPE_LIST[] = {
        {'s', &arg_string},
        {'S', &arg_printable},
        {'i', &arg_decimal},
        {'d', &arg_decimal},
        {'u', &arg_unsigned_int},
        {'x', &arg_hexa},
        {'X', &arg_hexa_upper},
        {'o', &arg_octal},
        {'p', &arg_pointer},
        {NULL, NULL}
    };

#endif /* !ARG_TYPE_H */
