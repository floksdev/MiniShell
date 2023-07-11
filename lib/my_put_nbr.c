/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include <stdio.h>
#include <math.h>

void  my_putchar(char c);
int my_put_nbr(int nbr)
{
    if (nbr < 0){
        my_putchar('-');
        nbr = nbr * -1;
    }
    if (nbr / 10 != 0){
        my_put_nbr(nbr / 10);
    }
    my_putchar(nbr % 10 + 48);
    return 0;
}
