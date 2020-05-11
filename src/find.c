/*
** EPITECH PROJECT, 2019
** find.c
** File description:
** find functions for bsq project
*/

#include "../include/my_bsq.h"

int find_smallest(map_t *map)
{
    int a = map->buffer[map->index_buf - map->left];
    int b = map->buffer[map->index_buf - map->top];
    int c = map->buffer[map->index_buf - map->top_left];
    if (a <= b && a <= c)
        return (a);
    else if (b <= a && b <= c)
        return (b);
    else
        return (c);
}

int find_biggest(map_t *map)
{
    int i = 0;
    int highest = 0;
    while (map->buffer[i] != -2) {
        if (map->buffer[i] > highest) {
            highest = map->buffer[i];
        }
        i++;
    }
    return (highest);
}