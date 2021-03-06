/*
** EPITECH PROJECT, 2019
** header
** File description:
** header for bsq project
*/

#ifndef MY_BSQ_H_
#define MY_BSQ_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct map {
    char *sv_map;
    char *new_map;
    int *buffer;
    int rows;
    int line_chars;
    int number_given;
    int br;
    int biggest;
    int skip;
    int index_buf;
    int top;
    int top_left;
    int left;
    int file_size;
} map_t;

int main(int ac, char **av);
void my_bsq(char *filepath);
void errors(map_t *map);
void first_line_error(map_t *map);
void processing(map_t *map);
void final2(map_t *map, int *i);
void replace2(map_t *map);
void number_of_lines_error(map_t *map);
int skip_first_line(map_t *map);
int find_rows(map_t *map);
int *map_replaced(map_t *map);
int *map_with_2(map_t *map);
int *map_with_square(map_t *map);
char *final_map(map_t *map);
int find_smallest(map_t *map);
int find_biggest(map_t *map);
int my_atoi(char const *str);
void my_putchar(char c);

#endif