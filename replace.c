/*
** EPITECH PROJECT, 2019
** my_bsq replace.c
** File description:
** replace functions for bsq project
*/

#include "include/my_bsq.h"

int *map_replaced(map_t *map)
{
    while (map->sv_map[map->skip] != '\0') {
        if (map->sv_map[map->skip] == '\n') {
            map->buffer[map->index_buf] = -1;
            map->skip++;
            map->index_buf++;
        }
        if (map->sv_map[map->skip] == '.') {
            map->buffer[map->index_buf] = 1;
            map->skip++;
            map->index_buf++;
        }
        if (map->sv_map[map->skip] == 'o') {
            map->buffer[map->index_buf] = 0;
            map->skip++;
            map->index_buf++;
        }
    }
    map->buffer[map->index_buf] = -2;
    map->index_buf = 0;
    return (map->buffer);
}

int *map_with_2(map_t *map)
{
    map->left = 1;
    map->top = (map->rows + 1);
    map->top_left = (map->rows + 2);
    map->index_buf = (map->index_buf + map->rows);
    while (map->buffer[map->index_buf] != -2) {
        if (map->buffer[map->index_buf] == 1) {
            if (map->buffer[map->index_buf - map->left] > 0 &&
            map->buffer[map->index_buf - map->top] > 0 &&
            map->buffer[map->index_buf - map->top_left] > 0) {
                map->buffer[map->index_buf] = (find_smallest(map) + 1);
            }
        }
        map->index_buf++;
    }
    return (map->buffer);
}

int *map_with_square(map_t *map)
{
    int i = 0;
    int xtime = map->biggest;
    int xtime2 = map->biggest;
    while (map->buffer[i] != map->biggest) {
        i++;
    }
    while (xtime != 0) {
        map->buffer[i] = -3;
        while (xtime2 != 0) {
            map->buffer[i - ((map->rows + 1) * (xtime2 - 1))] = -3;
            xtime2--;
        }
        xtime2 = map->biggest;
        xtime--;
        i--;
    }
    return (map->buffer);
}

char *final_map(map_t *map)
{
    int i = 0;
    while (map->buffer[i] != -2) {
        if (map->buffer[i] == 0) {
            map->new_map[i] = 'o';
            i++;
        } else if (map->buffer[i] > 0) {
            map->new_map[i] = '.';
            i++;
        } else if (map->buffer[i] == -1) {
            map->new_map[i] = '\n';
            i++;
        } else if (map->buffer[i] == -3) {
            map->new_map[i] = 'x';
            i++;
        }
    }
    map->new_map[i] = '\0';
    return (map->new_map);
}