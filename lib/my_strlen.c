/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_str_cmp
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen ( char *str )
{
    int i = 0;
    while (str[i] != '\0')
        i++;

    return i;
}
