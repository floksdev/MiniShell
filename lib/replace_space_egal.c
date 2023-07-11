/*
** EPITECH PROJECT, 2023
** shell2
** File description:
** replace_space
*/

#include <stdlib.h>
#include <stdbool.h>

int my_strlen ( char *str );

char *replace_space_egal (char *str)
{
    int length = my_strlen(str);
    char *result = malloc((length + 1) * sizeof(char));
    int i, j;
    bool test = false;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            result[j++] = '=';
            test = true;
        } else {
            result[j++] = str[i];
        }
    }
    if (!test)
        result[j++] = '=';

    result[j] = '\0';

    return result;
}
