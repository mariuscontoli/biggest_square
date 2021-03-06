/*
** EPITECH PROJECT, 2019
** replace.c
** File description:
** replace functions for bsq project
*/

#include "../include/my_bsq.h"

void replace2(map_t *map)
{
    if (map->sv_map[map->skip] == '.') {
        map->buffer[map->index_buf] = 1;
        map->skip++;
        map->index_buf++;
        map->line_chars += 1;
    } else if (map->sv_map[map->skip] == 'o') {
        map->buffer[map->index_buf] = 0;
        map->skip++;
        map->index_buf++;
        map->line_chars += 1;
    } else {
        exit (84);
    }
}

int *map_replaced(map_t *map)
{
    while (map->sv_map[map->skip] != '\0') {
        if (map->sv_map[map->skip] == '\n') {
            map->buffer[map->index_buf] = -1;
            map->skip++;
            map->index_buf++;
            map->br += 1;
            if (map->line_chars != map->rows)
                exit (84);
            map->line_chars = 0;
        } else {
            replace2(map);
        }
    }
    if (map->sv_map[map->skip - 1] != '\n')
        exit (84);
    map->buffer[map->index_buf] = -2;
    if (map->br != map->number_given)
        exit (84);
    errors(map);
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