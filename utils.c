/*
** EPITECH PROJECT, 2019
** my_bsq utils
** File description:
** utilitary functions for bsq project
*/

#include "include/my_bsq.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_atoi(char const *str)
{
    int i = 0;
    int tmp = 0;
    while (str[i] != '\0') {
        if (str[i] < 48 || str[i] > 57) {
            exit (84);
        }
        tmp = tmp * 10;
        tmp = tmp + str[i] - 48;
        i++;
    }
    return (tmp);
}