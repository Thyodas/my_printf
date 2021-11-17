/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-guillaume.hein
** File description:
** test_my_printf
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>

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

Test(my_printf, int_format_space, .init = redirect_all_std)
{
    my_printf("hello %10d\n", 1234);
    cr_assert_stdout_eq_str("hello       1234\n");
}