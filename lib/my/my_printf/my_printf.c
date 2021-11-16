/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "include/my_printf.h"
#include "../my.h"
#include "include/arg_type.h"

int get_flag_pos(char c);
arg_type_t get_type(const char *str);
printf_data_t *create_data_struct();
void show_data(printf_data_t *data);

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
        return (type.func(args, data));
    }
    return ("");
}

int format_identifier(const char *format, va_list args)
{
    int flag_size = 0;
    int i = 0;
    printf_data_t *data = create_data_struct();

    for (; format[i] != '\0' && data->str[0] == '\0' ; ++i) {
        flag_size = 0;
        if (flag_handling(&format[i], data))
            data->str = type_handling(&format[i], data, args);
    }
    show_data(data);
    free(data);
    return (i);
}

int my_printf_parser(const char *format, va_list args)
{
    int i = 0;
    int last_write = 0;

    for (; format[i] != '\0' ; ++i) {
        if (format[i] == '%') {
            write(1, &format[last_write], i - last_write);
            i += format_identifier(&format[i + 1], args);
            last_write = i + 1;
        }
    }
    write(1, &format[last_write], i - last_write);
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