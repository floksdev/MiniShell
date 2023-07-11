/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-tristan.wehrle
** File description:
** my_exec
*/

#include "./include/my.h"

int segfault_handling (int status, char *command)
{
    if (WIFSIGNALED(status)) {
        int signal_num = WTERMSIG(status);
        if (signal_num == SIGSEGV) {
            write(2, "Segmentation fault (core dumped)\n", 33);
            return signal_num + 128;
        }
        if (signal_num == SIGFPE) {
            write(2, "Floating exception (core dumped)\n", 33);
            return signal_num + 128;
        }
        if (signal_num == SIGABRT) {
            write(2, command, my_strlen(command));
            write(2, "Exec format error. Wrong Architecture.\n", 39);
            return signal_num + 128;
        }
        return signal_num + 128;
    }
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    return 0;
}

int pathenv2(char **env, char **tab, char *str)
{
    pid_t pid;
    int status = 0;
    char *slashfinal = cutspace(str);
    pid = fork();
    if (pid == 0) {
        execve(slashfinal, tab, env);
        remove_after_space(slashfinal);
        write(2, slashfinal, my_strlen(slashfinal));
        write(2, ": Command not found.\n", 21);
        exit(1);
    }
    wait(&status);
    return segfault_handling(status, slashfinal);
}
