/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** my_putstr
*/

#include <stdio.h>
void my_putchar(char c);
int my_putstr(char const *str)
{
    for (int count = 0; str[count] != '\0'; count++)
        my_putchar(str[count]);
    return (0);
}
