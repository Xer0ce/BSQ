/*
** EPITECH PROJECT, 2023
** BTTF BSQ
** File description:
** resolver
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "bsq.h"
#include "my.h"
#include "bsq_struct.h"

int print_map(char **map)
{
    for (int i = 1; map[i] != NULL; i++) {
        write(1, map[i], my_strlen(map[i]));
        my_putchar('\n');
    }
    return 0;
}

int check_point(bsq_t *bsq, int stop)
{
    if (bsq->map[bsq->y + bsq->check_y] == NULL)
        stop = 1;
    for (bsq->check_x = 0; bsq->check_x != bsq->scale &&
    stop != 1; bsq->check_x++) {
        if (bsq->map[bsq->y + bsq->check_y][bsq->x + bsq->check_x] == '\0')
            stop = 1;
        if (bsq->map[bsq->y + bsq->check_y][bsq->x + bsq->check_x] != '.')
            stop = 1;
    }
    return stop;
}

int browse_scale(bsq_t *bsq, int *coo_x_scale, int stop)
{
    for (bsq->scale = 2; stop == 0; bsq->scale++) {
        for (bsq->check_y = 0; bsq->check_y != bsq->scale; bsq->check_y++)
            stop = check_point(bsq, stop);
        if (coo_x_scale[2] < bsq->scale - 1) {
            coo_x_scale[0] = bsq->y;
            coo_x_scale[1] = bsq->x;
            coo_x_scale[2] = bsq->scale - 1;
        }
    }
    return stop;
}

int browse_map(bsq_t *bsq, int *coo_x_scale)
{
    int stop = 0;

    for (bsq->x = 0; bsq->map[bsq->y][bsq->x] != '\0'; bsq->x++) {
        stop = 0;
        if (bsq->map[bsq->y][bsq->x] == '.')
            stop = browse_scale(bsq, coo_x_scale, stop);
    }
    return 0;
}

int resolver(bsq_t *bsq)
{
    int *coo_x_scale;

    coo_x_scale = malloc(sizeof(int) * 3);
    for (bsq->y = 1; bsq->map[bsq->y] != NULL; bsq->y++)
        browse_map(bsq, coo_x_scale);
    for (int y = coo_x_scale[0]; y != coo_x_scale[0] + coo_x_scale[2]; y++) {
        for (int x = coo_x_scale[1]; x != coo_x_scale[1] + coo_x_scale[2]; x++)
            bsq->map[y][x] = 'x';
    }
    print_map(bsq->map);
    return 0;
}
