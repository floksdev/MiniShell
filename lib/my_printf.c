/*
** EPITECH PROJECT, 2022
** mini_printf.c
** File description:
** mini_printf
*/

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void my_putchar (char c);
int my_put_nbr(int nbr);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

int my_flags_condition(const char *format, va_list lst, int n)
{
    if (format[n] == 'c')
        my_putchar (va_arg(lst, int));
    if (format[n] == 's')
        my_putstr (va_arg(lst, char *));
    if (format[n] == 'i' || format[n] == 'd')
        my_put_nbr (va_arg(lst, int));
    if (format[n] == '%')
        my_putchar ('%');

return 0;
}

int my_printf(const char *format, ...)
{
    int n = 0;
    va_list lst;
    va_start(lst, format);

    while (format[n] != '\0') {
        if (format[n] == '%') {
            n++;
            my_flags_condition(format, lst, n);
        } else {
            my_putchar(format[n]);
        }
        n++;
    }
    va_end(lst);
    return 0;
}
