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

Test(my_printf, evil_mix3, .init = redirect_all_std)
{
    my_printf("fizz: %fbuzz%d%+10.2d%.2s", 123322.1, -100, 2, "marvin");
    cr_assert_stdout_eq_str("fizz: 123322.100000buzz-100       +02ma");
}

Test(my_printf, evil_mix4_octal_precision, .init = redirect_all_std)
{
    my_printf("fizz: %fbuzz%d%+10.10o%.2s", 123322.1, -100, 2222, "marvin");
    cr_assert_stdout_eq_str("fizz: 123322.100000buzz-1000000004256ma");
}

Test(my_printf, evil_mix_int_special_precision, .init = redirect_all_std)
{
    my_printf("fizz: %fbuzz%d%0+15.10d%.2s", 123322.1, -100, 2222, "marvin");
    cr_assert_stdout_eq_str("fizz: 123322.100000buzz-100    +0000002222ma");
}

Test(my_printf, evil_mix_int_special_precision2, .init = redirect_all_std)
{
    my_printf("fizz: %fbuzz%d%0+15.20d%.2s", 123322.1, -100, 2222, "marvin");
    cr_assert_stdout_eq_str(
        "fizz: 123322.100000buzz-100+00000000000000002222ma");
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

Test(my_printf, hex_special, .init = redirect_all_std)
{
    my_printf("%#+021.20x\n", 12344);
    cr_assert_stdout_eq_str("0x00000000000000003038\n");
}

Test(my_printf, multiple_tests, .init = redirect_all_std)
{
    my_printf("Characters: %c %c \n", 'a', 65);
    my_printf("Decimals: %d %ld \n", 1977, 650000L);
    my_printf("Preceding with blanks: %10d \n", 1977);
    my_printf("Preceding with zeros: %010d \n", 1977);
    my_printf("Some different radices: %d %x %o %#x %#o \n", 100,
    100, 100, 100, 100);
    my_printf("floats: %4.2f %+.0f %f \n", 3.1416, 3.1416, 3.1416);
    my_printf("Width trick: %5d \n", 10);
    my_printf("%s \n", "A string");
    cr_assert_stdout_eq_str("Characters: a A \n\
Decimals: 1977 650000 \n\
Preceding with blanks:       1977 \n\
Preceding with zeros: 0000001977 \n\
Some different radices: 100 64 144 0x64 0144 \n\
floats: 3.14 +3 3.141600 \n\
Width trick:    10 \n\
A string \n");
}

Test(my_printf, float_negative, .init = redirect_all_std)
{
    my_printf("%0+10.2f\n", -12344.2);
    cr_assert_stdout_eq_str("-012344.20\n");
}

Test(my_printf, int_zero_precision_zero, .init = redirect_all_std)
{
    my_printf("f% +020.d\n", 0);
    cr_assert_stdout_eq_str("f                   +\n");
}

Test(my_printf, uint_zero_precision_zero, .init = redirect_all_std)
{
    my_printf("f% +020.u\n", 0);
    cr_assert_stdout_eq_str("f                    \n");
}

Test(my_printf, long_zero_precision_zero, .init = redirect_all_std)
{
    my_printf("f% +020.ld\n", 0);
    cr_assert_stdout_eq_str("f                   +\n");
}

Test(my_printf, ulong_zero_precision_zero, .init = redirect_all_std)
{
    my_printf("f% +020.lu\n", 0);
    cr_assert_stdout_eq_str("f                    \n");
}

Test(my_printf, hexa_0_before, .init = redirect_all_std)
{
    my_printf("f% +020x\n", 0);
    cr_assert_stdout_eq_str("f00000000000000000000\n");
}

Test(my_printf, hexa_0_before2, .init = redirect_all_std)
{
    my_printf("f% +020x\n", 10);
    cr_assert_stdout_eq_str("f0000000000000000000a\n");
}

Test(my_printf, hexa_0_before_prefix, .init = redirect_all_std)
{
    my_printf("vhello %+#07x\n", 255);
    cr_assert_stdout_eq_str("vhello 0x000ff\n");
}
