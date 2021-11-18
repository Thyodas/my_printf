/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "include/flags.h"
#include "include/my_printf.h"
#include "../my.h"
#include "include/arg_type.h"

int get_flag_pos(char c);
arg_type_t get_type(const char *str);
printf_data_t *create_data_struct(void);
int flag_handling(const char *format, printf_data_t *data);
char *type_handling(const char *format, printf_data_t *data, va_list args);
int min_width_handling(const char *format, printf_data_t *data, va_list args);
int precision_handling(const char *format, printf_data_t *data, va_list args);

void show_data(printf_data_t *data)
{
    int i = 0;
    int formatted_len = data->min_field_width - my_strlen(data->str);
    char symbol = ' ';

    if (data->active_flags[F_POS_LEFT_JUSTIFY])
        my_putstr(data->str);
    if (!data->active_flags[F_POS_LEFT_JUSTIFY]
    && data->active_flags[F_POS_ZERO_PADDED] && data->is_nb) {
        if (data->str[0] == '+' || data->str[0] == '-'
        || data->str[0] == ' ') {
            i++;
            my_putchar(data->str[0]);
            data->str[0] = '0';
        }
        symbol = '0';
    }
    for (; i < formatted_len ; ++i)
        my_putchar(symbol);
    if (!data->active_flags[F_POS_LEFT_JUSTIFY])
        my_putstr(data->str);
}

int format_identifier(const char *format, va_list args)
{
    int i = 0;
    printf_data_t *data = create_data_struct();

    i += flag_handling(&format[i], data);
    i += min_width_handling(&format[i], data, args);
    i += precision_handling(&format[i], data, args);
    if (!type_handling(&format[i], data, args))
        return (0);
    show_data(data);
    free(data);
    return (i + 2);
}

int my_printf_parser(const char *format, va_list args)
{
    int i = 0;
    int last_write = 0;

    for (; format[i] != '\0' ; ++i) {
        if (format[i] == '%') {
            write(1, &format[last_write], i - last_write);
            i += format_identifier(&format[i + 1], args);
            last_write = i;
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
