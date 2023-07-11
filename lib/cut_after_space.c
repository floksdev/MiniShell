/*
** EPITECH PROJECT, 2023
** shell2
** File description:
** cut_after_space
*/

#include <stdio.h>

void remove_after_space(char *str)
{
    if (str == NULL)
        return;

    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            str[i] = '\0';
            break;
        }
    }
}
