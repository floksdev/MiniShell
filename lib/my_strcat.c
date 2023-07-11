/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-tristan.wehrle
** File description:
** my_strcat
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen ( char *str );

char *my_strcat(char *dest, char *src)
{
    int len = my_strlen(dest);
    int len2 = my_strlen(src);
    int plus = len + len2;
    char *str;
    char *final;
    str = malloc(sizeof(char) * (plus +  1));
    final = malloc(sizeof(char) * (plus + 1));
    for (int i = 0; dest[i] != '\0'; i++)
        str[i] = dest[i];

    for (int j = 0; src[j] != '\0'; j++)
        str[j + len] = src[j];

    for ( int h = 0; str[h] != '\0'; h++) {
        if (str[h] == ' ')
        str[h] = '\0';
        final[h] = str[h];
    }
    str[plus] = '\0';
    return final;
}
