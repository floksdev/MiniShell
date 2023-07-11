/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-tristan.wehrle
** File description:
** getpwd
*/

#include "./include/my.h"

char *get_old_pwd ( char **env )
{
    char *path;

    for (int i = 0; env[i] != NULL; i++){
    if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D' &&
        env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D' &&
        env[i][6] == '=' && env[i] != NULL)
            path = my_cut_startstr("OLDPWD=", env[i]);
    }

    return path;
}

char *get_home_path ( char **env )
{
    char *path;

    for (int i = 0; env[i] != NULL; i++){
    if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M' &&
        env[i][3] == 'E' && env[i][4] == '=' && env[i] != NULL)
            path = my_cut_startstr("HOME=", env[i]);
    }

    return path;
}
