/*
** EPITECH PROJECT, 2023
** shell2
** File description:
** unsetenv
*/

#include "./include/my.h"

char **unset_env(char *str, term_t *term)
{
    int size = my_tab_strlen(term->new_env);
    char **tab = str_to_w_array(str, ' ');
    int found = 0; int i = 0;
    while (i < size) {
        if (my_strn_cmp(tab[0], term->new_env[i], my_strlen(tab[0])) == 0) {
            found = 1;
            break;
        }
        i++;
    }
    if (found) {
        for (; i < size - 1; i++) {
            term->new_env[i] = term->new_env[i + 1];
        }
        term->new_env[size - 1] = NULL;
        return term->new_env;
    } else {
        return term->new_env;
    }
}
