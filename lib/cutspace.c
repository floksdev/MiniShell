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

char *cutspace (char *str)
{
    int len = my_strlen(str);
    char *str2 = malloc(sizeof(char) * (len + 1));
    int i = 0; int j = 0; int k = 0;
    for (; str[j] != '\0'; j++){
        if (str[j] == '\t')
            str[j] = ' ';
    }
    while (str[i] != '\0'){
        if (str[i] != ' ' || (i > 0 && str[i - 1] != ' ')){
            str2[k] = str[i];
            k++;
        }
        i++;
    }
    if (k > 0 && str2[k - 1] == ' ') {
        str2[k - 1] = '\0';
    } else
        str2[k] = '\0';
    return str2;
}
