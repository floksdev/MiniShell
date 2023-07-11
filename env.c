/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** env
*/

#include "./include/my.h"

int printenv ( char **env )
{
    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);

    return 0;
}

int compteur ( char **env )
{
    int i;
    for (i = 0; env[i] != NULL; i++){

    }

    return i;
}

char **copy_env (char **env)
{
    char **cpy = malloc(sizeof(char *) * (compteur(env) + 1));
    for (int i = 0; env[i] != NULL; i++){
        cpy[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        cpy[i] = env[i];
    }
    return cpy;
}

char **set_env(char *setenv_str, char *str, term_t *term)
{

    char **tab = str_to_w_array(setenv_str, ' ');
    char *envcmd = NULL;
    envcmd = replace_space_egal(setenv_str);
    int exists = 0;
    for (int i = 0; term->new_env[i] != NULL; i++){
        if (my_strn_cmp(term->new_env[i], tab[0], my_strlen(tab[0])) == 0){
            term->new_env[i] = envcmd;
            exists = 1;
            break;
        }
    }

    if_not_exist(term, envcmd, exists);
    if (good_args_setenv(setenv_str) == 2){
        write(2, "setenv: Too many arguments\n", 27);
        return term->return_value = 1;
    }
    return term->new_env;
}

void if_not_exist (term_t *term, char *envcmd, int exists)
{
        if (exists != 1) {
        int new_size = my_tab_strlen(term->new_env) + 2;
        char **new_env = malloc(sizeof(char *) * (new_size + 1));
        for (int i = 0; term->new_env[i] != NULL; i++) {
            new_env[i] = term->new_env[i];
        }
        new_env[new_size - 2] = envcmd;
        new_env[new_size - 1] = NULL;
        free(term->new_env);
        term->new_env = new_env;
    }
}
