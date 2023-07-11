/*
** EPITECH PROJECT, 2023
** cc
** File description:
** int my_cut_startstr
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str);
int my_str_cmp ( char *str1, char *str2);

char *my_cut_startstr ( char *strtocut, char *str )
{
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));
    int len1 = my_strlen(strtocut);
    int len2 = my_strlen(str);
    int lencut = len2 - len1;
    for (int i = 0; str[i] != '\0';i++) {
        str2[i] = str[i + len1];
    }
    str2[lencut] = '\0';
    return str2;
}
