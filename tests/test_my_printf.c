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

Test(my_printf, int_blank_padding_positive, .init = redirect_all_std)
{
    my_printf("hello %+ 10d\n", 1234);
    cr_assert_stdout_eq_str("hello      +1234\n");
}

Test(my_printf, float_basic, .init = redirect_all_std)
{
    float test = 1234.1234;
    my_printf("%10.10f\n", test);
    cr_assert_stdout_eq_str("1234.123413\n");
}

Test(my_printf, float_basic2, .init = redirect_all_std)
{
    float test = 189.238183;
    my_printf("%f", test);
    cr_assert_stdout_eq_str("189.238190");
}

Test(my_printf, float_basic3, .init = redirect_all_std)
{
    float test = 1239.623;
    my_printf("%.f", test);
    cr_assert_stdout_eq_str("1240");
}

Test(my_printf, float_basic4, .init = redirect_all_std)
{
    float test = 1239.623;
    my_printf("%.2f", test);
    cr_assert_stdout_eq_str("1239.62");
}

Test(my_printf, float_basic5, .init = redirect_all_std)
{
    float test = 1239.627;
    my_printf("%.2f", test);
    cr_assert_stdout_eq_str("1239.63");
}

Test(my_printf, float_basic6, .init = redirect_all_std)
{
    float test = 1239.627;
    my_printf("%f", test);
    cr_assert_stdout_eq_str("1239.626953");
}

Test(my_printf, float_error, .init = redirect_all_std)
{
    float test = 1239.627;
    my_printf("%.-2f", test);
    cr_assert_stdout_eq_str("%.-2f");
}

Test(my_printf, long_format, .init = redirect_all_std)
{
    my_printf("hello %ld\n", 6236788723886773);
    cr_assert_stdout_eq_str("hello 6236788723886773\n");
}

Test(my_printf, long_format_hard, .init = redirect_all_std)
{
    my_printf("hello %020ld\n", -6236788723886773);
    cr_assert_stdout_eq_str("hello -0006236788723886773\n");
}

Test(my_printf, long_unsigned_format, .init = redirect_all_std)
{
    my_printf("hello %lu\n", -623678872388);
    cr_assert_stdout_eq_str("hello 18446743450030679228\n");
}

Test(my_printf, long_unsigned_format_hard, .init = redirect_all_std)
{
    my_printf("hello %020lu\n", 6236788723886773);
    cr_assert_stdout_eq_str("hello 00006236788723886773\n");
}

Test(my_printf, long_unsigned_format_hard2, .init = redirect_all_std)
{
    my_printf("hello %-020lu\n", 6236788723886773);
    cr_assert_stdout_eq_str("hello 6236788723886773    \n");
}

Test(my_printf, mixed1, .init = redirect_all_std)
{
    my_printf("%s%d%#x", "azdpopaz\tazp", 82939, 99823);
    cr_assert_stdout_eq_str("azdpopaz\tazp829390x185ef");
}

Test(my_printf, error_modulo, .init = redirect_all_std)
{
    my_printf("%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, error_flag, .init = redirect_all_std)
{
    my_printf("%Vs", "hey");
    cr_assert_stdout_eq_str("%Vs");
}

Test(my_printf, weird_modulo1, .init = redirect_all_std)
{
    my_printf("%%%%%%");
    cr_assert_stdout_eq_str("%%%");
}

Test(my_printf, weird_modulo2, .init = redirect_all_std)
{
    my_printf("%+0%%%%-%");
    cr_assert_stdout_eq_str("%%%");
}

Test(my_printf, evil_mix, .init = redirect_all_std)
{
    my_printf("%ld%s%s%s% d%i%%%c", 6868687876329000001, "hello",
    "marvin", "", 0, -42, 0);
    cr_assert_stdout_eq_str("6868687876329000001hellomarvin 0-42%");
}

Test(my_printf, evil_mix2, .init = redirect_all_std)
{
    my_printf("%ld%s%s%c%s% d%i%%%c", 6868687876329000001, "hello",
    "marvin", 0, "", 0, -42, 0);
    cr_assert_stdout_eq_str("6868687876329000001hellomarvin 0-42%");
}

Test(my_printf, str_max_size, .init = redirect_all_std)
{
    my_printf("%.3s", "hello");
    cr_assert_stdout_eq_str("hel");
}

Test(my_printf, str_max_size2, .init = redirect_all_std)
{
    my_printf("%.sa", "hello");
    cr_assert_stdout_eq_str("a");
}

Test(my_printf, str_max_size3, .init = redirect_all_std)
{
    my_printf("%.10sa", "hello world");
    cr_assert_stdout_eq_str("hello worla");
}

Test(my_printf, str_max_size4, .init = redirect_all_std)
{
    my_printf("%.100000sa", "hello world");
    cr_assert_stdout_eq_str("hello worlda");
}

Test(my_printf, str_min_max_size, .init = redirect_all_std)
{
    my_printf("%10.sa", "hello");
    cr_assert_stdout_eq_str("          a");
}