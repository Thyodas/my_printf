/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "my_printf.h"
#include "my.h"
#include "arg_type.h"

int get_flag_pos(char c);
arg_type_t get_type(const char *str);

void print_data(printf_data_t *data) {
    printf("-: %i\n", data->active_flags[0]);
    printf("0: %i\n", data->active_flags[1]);
    printf("+: %i\n", data->active_flags[2]);
    printf("blank: %i\n", data->active_flags[3]);
    printf("#: %i\n", data->active_flags[4]);
}

int flag_handling(const char *format, printf_data_t *data)
{
    int flag_pos = 0;

    flag_pos = get_flag_pos(format[0]);
    if (flag_pos != -1) {
        data->active_flags[flag_pos] = 1;
        return (0);
    }
    return (1);
}

char *type_handling(const char *format, printf_data_t *data, va_list args)
{
    arg_type_t type = get_type(format);

    if (type.sign != NULL) {
        return (type.func(va_arg(args, void *), data));
    }
    return ("");
}

void init_flags(printf_data_t *data)
{
    for (int i = 0 ; i < 5 ; ++i)
        data->active_flags[i] = 0;
}

int format_identifier(const char *format, va_list args)
{
    int flag_size = 0;
    int i = 0;
    char *arg_format = "";
    printf_data_t *data = malloc(sizeof(printf_data_t));
    init_flags(data);
    for (; format[i] != '\0' ; ++i) {
        flag_size = 0;
        if (flag_handling(&format[i], data))
            arg_format = type_handling(&format[i], data, args);
        my_putstr(arg_format);
    }
    free(data);
    return (i);
}

int my_printf_parser(const char *format, va_list args)
{
    int i = 0;
    int format_len = my_strlen(format);
    int last_write = 0;

    for (; i < format_len ; ++i) {
        if (format[i] == '%') {
            write(1, &format[last_write], i - last_write);
            i += format_identifier(&format[i + 1], args);
            last_write = i;
        }
    }
    return (0);
}

int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);


    my_printf_parser(format, args);
    va_end(args);
    return (0);
}