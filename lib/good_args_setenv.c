/*
** EPITECH PROJECT, 2023
** shell2
** File description:
** good_args_setenv
*/

int good_args_setenv (char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ' ')
            count++;
    }
    if (count == 1)
        return 0;
    if (count == 0)
        return 1;
    if (count > 1)
        return 2;

    return 0;
}
