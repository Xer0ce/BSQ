/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** generator_map
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bsq.h"

struct generator {
    char *map;
    int i_map;
    int j;
    int scale;
};

int gen_map_ext(struct generator *gen, int len_motif, char **av)
{
    for (int nbc = 0; nbc != gen->scale; nbc++) {
        if (gen->j == len_motif)
            gen->j = 0;
        gen->map[gen->i_map] = av[2][gen->j];
        gen->i_map++;
        gen->j++;
    }
    gen->map[gen->i_map] = '\n';
    gen->i_map++;
    return 0;
}

int generator_map(char **av)
{
    struct generator *gen = malloc(sizeof(struct generator));
    gen->scale = my_atoi(av[1]);
    int len_motif = my_strlen(av[2]);
    int size = ((gen->scale * gen->scale) + gen->scale * 2);
    gen->i_map = 0;
    bsq_t *bsq = malloc(sizeof(bsq_t));

    gen->map = malloc(sizeof(char) * size + 1);
    gen->j = 0;
    for (int nbl = 0; nbl != gen->scale + 1; nbl++)
        gen_map_ext(gen, len_motif, av);
    gen->map[my_strlen(gen->map)] = '\0';
    bsq->map = str_to_word_array(gen->map, '\n');
    resolver(bsq);
    return 0;
}
