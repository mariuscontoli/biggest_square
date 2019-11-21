/*
** EPITECH PROJECT, 2019
** errors.c
** File description:
** error handling file
*/

#include "include/my_bsq.h"

void errors(map_t *map)
{
    at_least_line(map);
    first_line_error(map);
    char_errors(map);
}

void number_of_lines_error(map_t *map)
{
    if (map->number_given == 0) {
        exit (84);
    }
    if (map->number_given != (map->br -1)) {
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
}

void char_errors(map_t *map)
{
    int i = skip_first_line(map);

    while (map->sv_map[i] != '\0') {
        if (map->sv_map[i] != '.' &&
        map->sv_map[i] != 'o' &&
        map->sv_map[i] != '\n') {
            exit (84);
        }
        i++;
    }
    if (map->sv_map[i - 1] != '\n') {
        exit (84);
    }
}

void at_least_line(map_t *map)
{
    int i = 0;

    while (map->sv_map[i] != '\0') {
        if (map->sv_map[i] == '\n') {
            map->br += 1;
        }
        i++;
    }
    if (map->br < 1) {
        exit (84);
    }
}