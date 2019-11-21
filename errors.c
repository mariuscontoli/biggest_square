/*
** EPITECH PROJECT, 2019
** errors.c
** File description:
** error handling file
*/

#include "include/my_bsq.h"

void errors(map_t *map)
{
    first_line_error(map);
}

void number_of_lines_error(map_t *map)
{
    if (map->number_given == 0) {
        exit (84);
    }
}

void first_line_error(map_t *map)
{
    int i = 0;
    char *first_line_value = malloc(sizeof(char *) * 6);

    while (map->sv_map[i] != '\n') {
        if (map->sv_map[i] < 48 || map->sv_map[i] > 57) {
            exit (84);
        }
        first_line_value[i] = map->sv_map[i];
        i++;
    }
    first_line_value[i] = '\0';
    map->number_given = my_atoi(first_line_value);
    number_of_lines_error(map);
    free(first_line_value);
}