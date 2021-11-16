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

    char get_sign_char(int is_neg, printf_data_t *data);
    char *my_strlong_base(long nbr, char *str, char const *base);
    char *my_struint_base(unsigned int nbr, char *str, char const *base);
    char *my_strint_base(int nbr, char *str, char const *base);
    char *my_addchar(char *src, char c);

#endif /* !MY_PRINTF_H_ */
