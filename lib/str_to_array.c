/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** str_to_array
*/

#include <stdlib.h>

int lenght(char *str, char c)
{
    int x = 0;
    int i = 1;
    while (str[x] != '\0') {
        if (str[x] == c)
            i += 1;
        x += 1;
    }
    return i;
}

int first_w_len(char *str, char c)
{
    int len = 0;
    while (str[len] != c && str[len] != '\0')
        len ++;
    return (len);
}

int w_size(char *str, char c, int sep)
{
    int t_sep = 0;
    int len_w = 0; int len = 0; int w = 0;
    for (int i = 0; (t_sep < sep) && str[i] != '\0'; i++)
        (str[i] == c) ? t_sep++ : len_w++;
    len = len_w + sep;
    t_sep = 0;
    for (int i = 0; i < len; i++) {
        (str[i] == c) ? t_sep++ : 0;
        (t_sep == sep - 1 && str[i] != '\0') ? (w += 1) : 0;
    }
    return (w);
}

int len_size(char *str, char c, int sep)
{
    int t_sep = 0;
    int len_w = 0; int len = 0; int w = 0;
    for (int i = 0; (t_sep < sep) && str[i] != '\0'; i++)
        (str[i] == c) ? t_sep++ : len_w++;
    len = len_w + sep;
    t_sep = 0;
    for (int i = 0; i < len; i++) {
        (str[i] == c) ? t_sep++ : 0;
        (t_sep == sep - 1 && str[i] != '\0') ? (w += 1) : 0;
    }
    return (len);
}

char **str_to_w_array(char *str, char c)
{
    int nb_args = lenght(str, c);
    char **arr = malloc(sizeof(char *) * (nb_args + 1));
    int ind = 0; int sep = 1; int len = 0; int w = 0;
    while (ind < nb_args) {
        w = w_size(str, c, sep);
        len = len_size(str, c, sep);
        arr[ind] = malloc(sizeof(char) * (w + 1));
        int t_sep = 0;
        w = 0;
        for (int i = 0; i < len; i++) {
            (str[i] == c) ? t_sep++ : 0;
            (t_sep == sep - 1 && str[i] != '\0' && str[i] != c) ?
            (arr[ind][w] = str[i]) : 0;
            (t_sep == sep - 1 && str[i] != '\0' && str[i] != c) ? w += 1 : 0;
        }
        arr[ind][w] = '\0';
        w = 0; sep += 1; ind += 1;
    }
    arr[nb_args] = NULL;
    return (arr);
}
