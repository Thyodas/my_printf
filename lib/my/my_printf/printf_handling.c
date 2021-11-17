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
    int flag_pos = 0;
    //printf("\n=== %c ===\n", format[0]);
    flag_pos = get_flag_pos(format[0]);
    if (flag_pos != -1) {
        data->active_flags[flag_pos] = 1;
        return (1);
    }
    return (0);
}

char *type_handling(const char *format, printf_data_t *data, va_list args)
{
    arg_type_t type = get_type(format);

    if (type.sign != NULL) {
        return (type.func(args, data));
    }
    return ("");
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
    if (len <= 0 || format[0] == '0' || format[0] == '-')
        return (0);
    int value = my_getnbr(format);

    data->min_field_width = value;
    return (len - 1);
}

int precision_handling(const char *format, printf_data_t *data, va_list args)
{
    if (format[0] != '.')
        return (0);
    int len = get_nbr_len(&format[1]);
    if (len <= 0)
        return (0);
    int value = my_getnbr(&format[1]);

    data->precision = value;
    return (len);
}