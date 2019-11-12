/*
** EPITECH PROJECT , 2019
** fs_open_file
** File description :
** fs_open_file
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int skip_first_line(char const *buffer)
{
    int i = 0;
    int k = 0;
    int count = 0;
    for (; buffer[i]; i++)
    {
        if (buffer[i] == '\n')
            break;
    }
    return (i + 1);
}

int find_rows(char const *buffer, int i)
{
    int count = 0;
    for (; buffer[i] != '\n'; i++) {
        count++;
    }
    return (count);
}

char *map_replaced(char *buffer, int i, int rows)
{
    int j = i;
    while (buffer[i] != '\n') {
        if (buffer[i] == '.') {
            buffer[i] = '1';
        }
        i++;
    }
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            i++;
            if (buffer[i] == '.') {
                buffer[i] = '1';
            }
        }
        i++;
    }
    return (buffer);
}

char *map_with_2(char *buffer, int i, int rows)
{
    int j;
    j = i + rows + 1;
    while (buffer[j] != '\0') {
        if (buffer[j] == '.') {
            if (buffer[j - 1] == '1' && buffer[j - (rows + 1)] == '1' && buffer[j - (rows + 2)] == '1') {
                buffer[j] = '2';
            } else {
                buffer[j] = '1';
            }  
        }
        j++; 
    }
    return (buffer);
}

char *bsq(char const *filepath)
{
    int size = 20001;
    int rows = 0;
    int skip = 0;
    char *buffer[size];
    int **map;
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        return 84;
    }
    read(fd, buffer, size);
    skip = skip_first_line(buffer);
    rows = find_rows(buffer, skip);
    return map_with_2((map_replaced(buffer, skip, rows)), skip, rows);
}

int main(int ac, int **ag)
{
    my_putstr(bsq(ag[1]));
    return (0);
}