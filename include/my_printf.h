/*
** EPITECH PROJECT, 2021
** my_printf.h
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

    #include <unistd.h>
    typedef struct printf_data_s {
        char *str;
        int active_flags[5];
    } printf_data_t;

    #define ABS(value) (value < 0 ? (value) * (-1) : (value))

#endif /* !MY_PRINTF_H_ */
