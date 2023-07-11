/*
** EPITECH PROJECT, 2023
** shell2
** File description:
** my_tab_strlen
*/

#include <stdio.h>

int my_tab_strlen(char **tab)
{
    int length = 0;
    if (tab != NULL) {
        while (tab[length] != NULL) {
            length++;
        }
    }
    return length;
}
