/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-tristan.wehrle
** File description:
** cd
*/

#include "./include/my.h"

int cd_function (term_t *term, char **env, const char *str)
{
    char *str2 = cutspace((char *)str);
    int result = chdir(str2);
    if (my_strn_cmp(str2, "-", 1) == 0)
        cd_dash(env);
    if (my_strn_cmp(str2, "~", 1) == 0 || str2 == NULL){
        cd_tilde(env);
    }
    if (result != 0 && my_strn_cmp(str2, "-", 1) == 1 &&
    my_strn_cmp(str2, "~", 1) == 1) {
    remove_after_space(str2);
    write(2, str2, my_strlen(str2));
    write(2, ": No such file or directory.\n", 29);
    term->return_value = 1;
    }
    return result;
}

int cd_dash (char **env)
{
        char path[1000];
        char *str = get_old_pwd(env);
        chdir(str);
        if (getcwd(path, sizeof(path)) == NULL)
            perror(" ");
        else
            my_printf("%s\n", path);
    return 0;
}

char *get_home_dir (char **env)
{
    char *path = getpath(env);
    char *str = malloc(sizeof(char) * (my_strlen(path) + 1));
    char **buffer = str_to_w_array(path, '/');

    for (int i = 0; i != 3; i++)
        str = buffer[1];

    return str;
}

int cd_tilde (char **env)
{
    char *str = get_home_path(env);
    chdir(str);

    return 0;
}
