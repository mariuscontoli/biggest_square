/*
** EPITECH PROJECT , 2019
** fs_open_file
** File description :
** fs_open_file
*/

#include "my_bsq.h"

int skip_first_line(map_t *map)
{
    int i = 0;
    int k = 0;
    int count = 0;
    for (; map->buffer[i]; i++)
    {
        if (map->buffer[i] == '\n')
            break;
    }
    return (i + 1);
}

int find_rows(map_t *map)
{
    int count = 0;
    for (; map->buffer[map->rows] != '\n'; map->rows++) {
        count++;
    }
    return (count);
}

int *map_replaced(int *buffer, int i, int rows)
{
    int j = i;
    while (buffer[i] != '\n') {
        if (buffer[i] == 46) {
            buffer[i] = 1;
        }
        i++;
    }
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            i++;
            if (buffer[i] == 46) {
                buffer[i] = 1;
            }
        }
        i++;
    }
    return (buffer);
}

int *map_with_2(int *buffer, int i, int rows)
{
    int j;
    j = i + rows + 1;
    while (buffer[j] != '\0') {
        if (buffer[j] == 46) {
            if (buffer[j - 1] == 1 && buffer[j - (rows + 1)] == 1 && buffer[j - (rows + 2)] == 1) {
                buffer[j] = 2;
            } else {
                buffer[j] = 1;
            }  
        }
        j++; 
    }
    return (buffer);
}

void my_bsq(char *filepath)
{
    map_t *map = malloc(sizeof(*map));
    struct stat off_t;
    int size2 = 0;
    int test =0;
    int fd = open(filepath, O_RDONLY);
    size2 = stat(filepath, &off_t);
    if (fd == -1 || size2 < 0) {
        exit (84);
    }
    map->buffer = malloc(sizeof(char) * (off_t.st_size + 1));
    read(fd, map->buffer, off_t.st_size);
    map->rows = skip_first_line(map);
    my_putstr(map->buffer);
    free(map->buffer);
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