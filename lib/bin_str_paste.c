/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** env
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int my_strlen ( char *str );
char *my_strcat(char *dest, char const *src);

char *bin_str_paste (char *str)
{
    char *str2;
    str2 = malloc(sizeof(char) * 999);
    char *final_str;
    str2 = my_strcat("/bin/", str);

    return str2;
}
