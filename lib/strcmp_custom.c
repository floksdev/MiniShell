/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-tristan.wehrle
** File description:
** strcmp_custom
*/

#include <stdio.h>

int strcmp_custom (const char* str1, const char* str2)
{
    return (!my_strn_cmp(str1, str2, my_strlen(str2)));
}
