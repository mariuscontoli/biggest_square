/*
** EPITECH PROJECT , 2019
** fs_open_file
** File description :
** fs_open_file
*/

#include "include/my_bsq.h"

int skip_first_line(map_t *map)
{
    int i = 0;
    for (; map->sv_map[i]; i++)
    {
        if (map->sv_map[i] == '\n')
            break;
    }
    return (i + 1);
}

int find_rows(map_t *map)
{
    int count = 0;
    int i = map->skip;
    for (; map->sv_map[i] != '\n'; i++) {
        count++;
    }
    return (count);
}

void processing(map_t *map)
{
    map->skip = skip_first_line(map);
    map->rows = find_rows(map);
    map->buffer = map_replaced(map);
    map->buffer = map_with_2(map);
    map->biggest = find_biggest(map);
    map->buffer = map_with_square(map);
    map->new_map = final_map(map);
    map->skip = skip_first_line(map);
}

void my_bsq(char *filepath)
{
    map_t *map = malloc(sizeof(*map));
    struct stat off_t;
    map->index_buf = 0;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &off_t);
    map->file_size = off_t.st_size;
    if (fd == -1 || map->file_size < 0) {
        exit (84);
    }
    map->sv_map = malloc(sizeof(char) * (off_t.st_size + 1));
    map->buffer = malloc(sizeof(int) * (off_t.st_size + 1));
    map->new_map = malloc(sizeof(char) * (off_t.st_size + 1));
    read(fd, map->sv_map, off_t.st_size);
    errors(map);
    processing(map);
    write(1, map->new_map, off_t.st_size - map->skip);
    free(map->sv_map);
    free(map->buffer);
    free(map->new_map);
    free(map);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        return (84);
    } else {
        my_bsq(av[1]);
    }
    return (0);
}