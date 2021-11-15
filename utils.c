/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** flag_funcs
*/

#include "flags.h"
#include "arg_type.h"
#include "my.h"

int get_flag_pos(char c)
{
    int i = 0;

    for (; FLAG_LIST[i] != '\0' ; ++i)
        if (FLAG_LIST[i] == c)
            return (i);
    return (-1);
}

arg_type_t get_type(const char *str)
{
    int i = 0;

    for (; ARG_TYPE_LIST[i].sign != NULL ; ++i) {
        if (my_strncmp(str, ARG_TYPE_LIST[i].sign, ARG_TYPE_LIST[i].len) == 0)
            return (ARG_TYPE_LIST[i]);
    }
    return (ARG_TYPE_LIST[i]);
}