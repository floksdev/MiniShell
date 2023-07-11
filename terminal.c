/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** terminal
*/

#include "./include/my.h"

void terminal ( term_t *term, char **env )
{
    size_t len = 0; char *str = NULL; char *sepnospace = NULL;
    char **tab = NULL; char *separator = NULL;
    init_struct(term);
    if (isatty(0))
        my_putstr("$> ");
    term->new_env = copy_env(env);
    while (getline(&str, &len, stdin) != -1) {
        str[my_strlen(str) - 1] = '\0';
        separator = strtok(str, ";|");
        while (separator != NULL) {
            sepnospace = cutspace(separator);
            tab = str_to_w_array(sepnospace, ' ');
            term->return_value = conditions_input(term, env, tab, sepnospace);
            conditions_input2(term, env, tab, sepnospace);
            separator = strtok(NULL, ";|");
        }
        if (isatty(0))
            my_putstr("$> ");
    }
    free(str); free(tab);
}
