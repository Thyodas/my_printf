/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** printf_handling
*/

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
    int i = 0;

    for (; get_flag_pos(format[i]) != -1 ; ++i) {
        data->active_flags[get_flag_pos(format[i])] = 1;
    }
    return (i);
}

char *type_handling(const char *format, printf_data_t *data, va_list args)
{
    arg_type_t type = get_type(format);

    if (type.sign != NULL) {
        data->str = type.func(args, data);
        return (type.len);
    }
    return (0);
}

int get_nbr_len(const char *format)
{
    int i = 0;

    for (; '0' <= format[i] && format[i] <= '9' ; ++i);
    return (i);
}

int min_width_handling(const char *format, printf_data_t *data, va_list args)
{
    int len = get_nbr_len(format);
    if (len <= 0 || format[0] == '-')
        return (0);
    int value = my_getnbr(format);

    data->min_field_width = value;
    return (len);
}

int precision_handling(const char *format, printf_data_t *data, va_list args)
{
    int len = get_nbr_len(&format[1]);

    if (format[0] != '.' || len <= 0)
        return (0);
    int value = my_getnbr(&format[1]);

    data->precision = value;
    return (len + 1);
}
