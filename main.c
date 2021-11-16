/*
** EPITECH PROJECT, 2021
** TEST ONLY
** File description:
** main
*/

#include "my.h"
#include <stdlib.h>

int my_printf(const char *format, ...);

int main(void)
{
    char *test = my_strdup("salut");
    int testint = 1234;
    my_printf("String: %s\n", "hello!");
    my_printf("Hexa: %#x\n", 255);
    my_printf("HEXA: %#X\n", 255);
    my_printf("str=%s, ptr=%p\n", test, test);
    printf("str=%s, ptr=%p\n", test, test);
    my_printf("num_ptr=%p\n", &testint);
    printf("num_ptr=%5p\n", &testint);
}