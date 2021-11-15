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

int get_flag_pos(char c);

void print_data(printf_data_t *data) {
    printf("-: %i\n", data->active_flags[0]);
    printf("0: %i\n", data->active_flags[1]);
    printf("+: %i\n", data->active_flags[2]);
    printf("blank: %i\n", data->active_flags[3]);
    printf("#: %i\n", data->active_flags[4]);
}

int flag_handling(const char *format, va_list args, printf_data_t *data)
{
    int flag_pos = 0;
    int i = 0;

    for (; format[i] != '\0' && format[i] != 's' ; ++i) {
        flag_pos = get_flag_pos(format[i]);
        my_putchar(format[i]);
        my_put_nbr(flag_pos);
        my_putchar('\n');
        //printf("flag_pos %c: %i\n", format[i], flag_pos);
        if (flag_pos < 5)
            data->active_flags[flag_pos] = 1;
    }
    return (i);
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
    printf_data_t *data = malloc(sizeof(print_data));
    init_flags(data);
    //print_data(&data);
    for (; format[i] != '\0' ; ++i) {
        //printf("test");
        flag_size = 0;
        flag_size += flag_handling(&format[i], args, data);
        //flag_size += min_width_handling(format, args);
        //flag_size += arg_handling(format, args);
        i += flag_size;
    }
    //print_data(&data);
    return (i);
}

int my_printf_parser(const char *format, va_list args)
{
    int i = 0;

    for (; format[i] != '\0'; ++i) {
        if (format[i] == '%') {
            i += format_identifier(&format[i + 1], args);
        }
    }
}

int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);


    my_printf_parser(format, args);
    va_end(args);
    return (0);
}