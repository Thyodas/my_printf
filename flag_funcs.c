/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** flag_funcs
*/

#include "flags.h"

int get_flag_pos(char c)
{
    int i = 0;

    for (; FLAG_LIST[i] != NULL ; ++i)
        if (FLAG_LIST[i] == c)
            return (i);
    return (5);
}