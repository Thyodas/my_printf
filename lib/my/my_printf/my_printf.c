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
printf_data_t *create_data_struct();
int flag_handling(const char *format, printf_data_t *data);
char *type_handling(const char *format, printf_data_t *data, va_list args);
int min_width_handling(const char *format, printf_data_t *data, va_list args);
int precision_handling(const char *format, printf_data_t *data, va_list args);

void show_data(printf_data_t *data)
{
    int len = my_strlen(data->str);
    int formatted_len = data->min_field_width - len;

    if (data->active_flags[F_POS_LEFT_JUSTIFY])
        my_putstr(data->str);
    for (int i = 0 ; i < formatted_len ; ++i)
        my_putchar(data->active_flags[F_POS_ZERO_PADDED] ? '0' : ' ');
    if (!data->active_flags[F_POS_LEFT_JUSTIFY])
        my_putstr(data->str);
}

int format_identifier(const char *format, va_list args)
{
    int i = 0;
    int flag_len = 0;
    printf_data_t *data = create_data_struct();

    for (; format[i] != '\0' && data->str[0] == '\0' ; ++i) {
        if (data->precision == 0)
            precision_handling(&format[i], data, args);
        if (data->precision == 0 && data->min_field_width == 0)
            min_width_handling(&format[i], data, args);
        if (data->precision == 0 && data->min_field_width == 0)
            flag_len = flag_handling(&format[i], data);
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