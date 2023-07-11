/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strn_cmp
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen ( char *str );

int my_strn_cmp ( char *str1, char *str2, int n )
{
    if (my_strlen(str1) < n || my_strlen(str2) < n)
        return 1;
    for (int i = 0; i < n; i++) {
        if ( str1[i] != str2[i])
            return 1;
    }
    return 0;
}
