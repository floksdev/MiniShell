/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** terminal
*/

#include "./include/my.h"

int pathenv_handling(char *strnospace, term_t *term, char **tab, char *str)
{
    if (my_strn_cmp(strnospace, "env", 3) == 1 &&
    strcmp_custom(strnospace, "./") == 0
    && my_strn_cmp(strnospace, "setenv", 6) == 1
    && strcmp_custom(strnospace, "setenv ") == 0
    && my_strn_cmp(strnospace, "setenv ", 7) == 1
    && my_strn_cmp(strnospace, "unsetenv", 8) == 1
    && my_strn_cmp(strnospace, "unsetenv ", 9) == 1 && str[0] != '\0')
        return pathenv(term, tab, str);
    return 0;
}

int conditions_input(term_t *term, char **env, char **tab, char *str)
{
    char *strnospace = cutspace(str);
    char *cutstr = my_cut_startstr("cd ", strnospace);
    if ((strcmp_custom(strnospace, "./") == 1 ||
    my_strn_cmp(strnospace, "/", 1) == 0) && str[0] != '\0') {
        return pathenv2(env, tab, str);
    }
    if (my_str_cmp(strnospace, "exit\0") == 0 && str[0] != '\0') {
        exit(0);
    }
    if (my_strn_cmp(strnospace, "cd\0", 3) == 0 &&
    strcmp_custom(strnospace, "cd ") == 0 && str[0] != '\0') {
        cd_tilde(env);
        return term->return_value;
    }
    if (strcmp_custom(strnospace, "cd ") == 1 && str[0] != '\0') {
        cd_function(term, env, cutstr);
        return term->return_value;
    }
    return pathenv_handling(strnospace, term, tab, str);
    return 0;
}

int conditions_input2 (term_t *term, char **env, char **tab, char *str)
{
    char *strnospace = cutspace(str);
    char *setenv_str = my_cut_startstr("setenv ", str);
    char *unsetenv_str = my_cut_startstr("unsetenv ", str);
    if (my_strn_cmp(strnospace, "setenv ", 7) == 0
    && (good_args_setenv(setenv_str) != 1 ||
    good_args_setenv(setenv_str) == 1)){
        term->new_env = set_env(setenv_str, str, term);
    }
    if (my_strn_cmp(strnospace, "setenv", 6) == 0 &&
    strcmp_custom(strnospace, "setenv ") == 0)
        printenv(term->new_env);
    if (my_strn_cmp(strnospace, "unsetenv", 8) == 0 &&
    strcmp_custom(strnospace, "setenv ") == 0)
        term->new_env = unset_env(unsetenv_str, term);

    if (my_strn_cmp(strnospace, "env", 3) == 0 &&
    strcmp_custom(strnospace, "setenv ") == 0 && str[0] != '\0')
        printenv(term->new_env);
    return 0;
}
