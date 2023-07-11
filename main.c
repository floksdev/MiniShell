/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** main
*/

#include "./include/my.h"

int main ( int ac, char **av, char **env )
{
    term_t term = {0};
    if (ac == 1)
        terminal(&term, env);
    else
        return 84;
    return term.return_value;
}
