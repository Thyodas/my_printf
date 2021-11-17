/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-guillaume.hein
** File description:
** test_my_printf
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

int my_printf(const char *format, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, string_format, .init = redirect_all_std)
{
    my_printf("hello %s\n", "world");
    cr_assert_stdout_eq_str("hello world\n");
}

Test(my_printf, string_format_space, .init = redirect_all_std)
{
    my_printf("hello %10s\n", "world");
    cr_assert_stdout_eq_str("hello      world\n");
}

Test(my_printf, string_format_space_left, .init = redirect_all_std)
{
    my_printf("hello %-10s\n", "world");
    cr_assert_stdout_eq_str("hello world     \n");
}

Test(my_printf, int_format, .init = redirect_all_std)
{
    my_printf("hello %d\n", 1234);
    cr_assert_stdout_eq_str("hello 1234\n");
}

Test(my_printf, int_format2, .init = redirect_all_std)
{
    my_printf("hello %i\n", 1234);
    cr_assert_stdout_eq_str("hello 1234\n");
}

Test(my_printf, int_format_neg, .init = redirect_all_std)
{
    my_printf("hello %d\n", -1234);
    cr_assert_stdout_eq_str("hello -1234\n");
}

Test(my_printf, int_format_space, .init = redirect_all_std)
{
    my_printf("hello %10d\n", 1234);
    cr_assert_stdout_eq_str("hello       1234\n");
}

Test(my_printf, int_format_space_positive, .init = redirect_all_std)
{
    my_printf("hello % d\n", 1234);
    cr_assert_stdout_eq_str("hello  1234\n");
}

Test(my_printf, int_format_space_zero_positive, .init = redirect_all_std)
{
    my_printf("hello % d\n", 0);
    cr_assert_stdout_eq_str("hello  0\n");
}

Test(my_printf, int_format_plus_positive, .init = redirect_all_std)
{
    my_printf("hello %+d\n", 1234);
    cr_assert_stdout_eq_str("hello +1234\n");
}

Test(my_printf, int_format_plus_zero_positive, .init = redirect_all_std)
{
    my_printf("hello %+d\n", 0);
    cr_assert_stdout_eq_str("hello +0\n");
}

Test(my_printf, int_format_space_left, .init = redirect_all_std)
{
    my_printf("hello %-10d\n", 1234);
    cr_assert_stdout_eq_str("hello 1234      \n");
}

Test(my_printf, mix_str_int, .init = redirect_all_std)
{
    my_printf("hello %d %s\n", 1234, "hey");
    cr_assert_stdout_eq_str("hello 1234 hey\n");
}

Test(my_printf, hex_prefix, .init = redirect_all_std)
{
    my_printf("aba%#xdad", 1234);
    cr_assert_stdout_eq_str("aba0x4d2dad");
}

Test(my_printf, HEX_prefix, .init = redirect_all_std)
{
    my_printf("aba%#Xdad", 1234);
    cr_assert_stdout_eq_str("aba0X4D2dad");
}

Test(my_printf, binary, .init = redirect_all_std)
{
    my_printf("aba%bdad", 254);
    cr_assert_stdout_eq_str("aba11111110dad");
}

Test(my_printf, octal_prefix, .init = redirect_all_std)
{
    my_printf("aba%#odad", 1234);
    cr_assert_stdout_eq_str("aba02322dad");
}

Test(my_printf, unsigned_int, .init = redirect_all_std)
{
    my_printf("aba%udad", -1234);
    cr_assert_stdout_eq_str("aba4294966062dad");
}

Test(my_printf, modulo, .init = redirect_all_std)
{
    my_printf("aba%+-0#%dad");
    cr_assert_stdout_eq_str("aba%dad");
}

Test(my_printf, printable, .init = redirect_all_std)
{
    char str[3];
    my_strcpy(str , "ab");
    str[0] = 6;
    str[1] = 127;
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("\\006\\177\n");
}

Test(my_printf, int_zero_padding_neg, .init = redirect_all_std)
{
    my_printf("hello %0+10d\n", -1234);
    cr_assert_stdout_eq_str("hello -000001234\n");
}

Test(my_printf, int_zero_padding_positive, .init = redirect_all_std)
{
    my_printf("hello %0+10d\n", 1234);
    cr_assert_stdout_eq_str("hello +000001234\n");
}

Test(my_printf, int_zero_padding_blank, .init = redirect_all_std)
{
    my_printf("hello %0 10d\n", 1234);
    cr_assert_stdout_eq_str("hello  000001234\n");
}

Test(my_printf, int_blank_padding_blank, .init = redirect_all_std)
{
    my_printf("hello % 10d\n", 1234);
    cr_assert_stdout_eq_str("hello       1234\n");
}