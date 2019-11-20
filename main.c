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

char replace(map_t *map, int i)
{
    if (map->buffer[i] > 0)
        return ('.');
    if (map->buffer[i] = 0)
        return ('o');
    if (map->buffer[i] = -1)
        return ('\n');
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

int print_buffer(map_t *map)
{
    int i = 0;
    while (map->buffer[i] >= -1 || map->buffer[i] == -3) {
        if (map->buffer[i] == -1 && map->buffer[i + 1] != -2) {
            my_put_nbr(map->buffer[i]);
            my_putchar('\n');
            i += 1;
        }
        my_put_nbr(map->buffer[i]);
        i += 1;
    }
    return (0);
}

void my_bsq(char *filepath)
{
    map_t *map = malloc(sizeof(*map));
    struct stat off_t;
    map->index_buf = 0;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &off_t);
    map->file_size = off_t.st_size;
    if (fd == -1) {
        exit (84);
    }
    map->sv_map = malloc(sizeof(char) * (off_t.st_size + 1));
    map->buffer = malloc(sizeof(int) * (off_t.st_size + 1));
    map->new_map = malloc(sizeof(char) * (off_t.st_size + 1));
    read(fd, map->sv_map, off_t.st_size);
    map->skip = skip_first_line(map);
    map->rows = find_rows(map);
    map->buffer = map_replaced(map);
    map->buffer = map_with_2(map);
    map->biggest = find_biggest(map);
    map->buffer = map_with_square(map);
    map->new_map = final_map(map);
    map->skip = skip_first_line(map);
    write(1, map->new_map, off_t.st_size - map->skip);
    free(map->sv_map);
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