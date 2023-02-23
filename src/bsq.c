/*
** EPITECH PROJECT, 2023
** BTTF BSQ
** File description:
** bsq
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include "bsq.h"
#include "my.h"
#include "bsq_struct.h"

int bsq(char *path)
{
    int fd = 0;
    char *map_s = NULL;
    struct stat buf;
    bsq_t *bsq;

    bsq = malloc(sizeof(bsq_t));
    stat(path, &buf);
    map_s = malloc(sizeof(char) * buf.st_size);
    fd = open(path, O_RDONLY);
    read(fd, map_s, buf.st_size);
    bsq->map = str_to_word_array(map_s, '\n');
    resolver(bsq);
    return 0;
}
