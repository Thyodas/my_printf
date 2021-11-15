/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** arg_type
*/

#ifndef FLAGS_H_
#define FLAGS_H_

    #include "my_printf.h"
    #include <unistd.h>

    #define F_POS_SHOW_POSITIVE 0
    #define F_POS_LEFT_JUSTIFY 1
    #define F_POS_PREFIX 2
    #define F_POS_BLANK_POSITIVE 3
    #define F_POS_ZERO_PADDED 4

    const char FLAG_LIST[] = "+-# 0\0"

#endif /* !FLAGS_H_ */
