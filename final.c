/*
** EPITECH PROJECT, 2019
** final.c
** File description:
** final functions for bsq project
*/

#include "include/my_bsq.h"

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
    int *j = &i;
    while (map->buffer[i] != -2) {
        if (map->buffer[i] == 0) {
            map->new_map[i] = 'o';
            i += 1;
        } else {
            final2(map, j);
        }
    }
    map->new_map[i] = '\0';
    return (map->new_map);
}

void final2(map_t *map, int *i)
{
    if (map->buffer[*i] > 0) {
        map->new_map[*i] = '.';
        *i += 1;
    } else if (map->buffer[*i] == -1) {
        map->new_map[*i] = '\n';
        *i += 1;
    } else if (map->buffer[*i] == -3) {
        map->new_map[*i] = 'x';
        *i += 1;
    }
}