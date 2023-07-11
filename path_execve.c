/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-tristan.wehrle
** File description:
** path_execve
*/

#include "./include/my.h"

int pathenv(term_t *term, char **tab, char *str)
{
    char *path_with_parse = getpath(term->new_env);
    char **tabi = str_to_w_array(path_with_parse, ':');
    pid_t pid;
    int status = 0;
    char *slashfinal = cutspace(str);
    char *slash = my_strcat("/", slashfinal);
    char *noparse_str = NULL;
    pid = fork();
    if (pid == 0){
        for (int i = 0; tabi[i] != NULL; i++) {
            noparse_str = my_strcat(tabi[i], slash);
            execve(noparse_str, tab, term->new_env);
        }
        return normal_not_found(slashfinal);
    }
    wait(&status);
    if (pid == -1)
    exit(EXIT_FAILURE);
    return segfault_handling(status, slashfinal);
}

int normal_not_found (char *slashfinal)
{
    remove_after_space(slashfinal);
    if (strcmp_custom(slashfinal, "./") == 0
    && strcmp_custom(slashfinal, "env") == 0){
        write(2, slashfinal, my_strlen(slashfinal));
        write(2, ": Command not found.\n", 21);
        exit(1);
    }
    return 0;
}

char *getpath ( char **env )
{
    char *path;

    for (int i = 0; env[i] != NULL; i++){
    if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
        env[i][3] == 'H' && env[i][4] == '=' && env[i] != NULL){
            path = my_cut_startstr("PATH=", env[i]);
    }
    }

    return path;
}
