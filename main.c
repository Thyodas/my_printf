/*
** EPITECH PROJECT, 2021
** TEST ONLY
** File description:
** main
*/

#include "my.h"

int my_printf(const char *format, ...);

int main(void)
{
    my_printf("String: %s\n", "hello!");
    my_printf("Hexa: %#x\n", 255);
    my_printf("HEXA: %#X\n", 255);
}