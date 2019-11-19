#ifndef MY_BSQ_H_
#define MY_BSQ_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct map {
    char *buffer;
    int rows;
    int columns;
    int size;
} map_t;

int main(int ac, char **av);
void my_bsq(char *filepath);
int my_putstr(char const *str);
void my_putchar(char c);

#endif