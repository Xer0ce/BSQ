/*
** EPITECH PROJECT, 2023
** BTTF BSQ
** File description:
** main
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"
#include "my.h"

int main_extension(char **argv)
{
    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (argv[1][i] >= '0' && argv[1][i] <= '9') {
        } else
            return 84;
    }
    for (int i = 0; argv[2][i] != '\0'; i++) {
        if (argv[2][i] != '.' && argv[2][i] != 'o')
            return 84;
    }
    return 0;
}

int error_gest_ext(char *buffer, struct stat buf)
{
    int deb;
    char **map = str_to_word_array(buffer, '\n');

    if (buffer[0] <= '0' || buffer[0] >= '9')
        return 84;
    for (deb = 0; buffer[deb] != '\n'; deb++);
    for (int i = deb; i != buf.st_size; i++) {
        if (buffer[i] != '.' && buffer[i] != 'o' && buffer[i] != '\n')
            return 84;
    }
    for (int i = 1; map[i] != NULL; i++) {
        if (map[i + 1] == NULL)
            return 0;
        if (my_strlen(map[i]) != my_strlen(map[i + 1]))
            return 84;
    }
    return 0;
}

int error_gest_arc2(char **arv)
{
    struct stat buf;
    int fd = 0;
    char *buffer;

    if (stat(arv[1], &buf) == -1)
        return 84;
    if (buf.st_size == 0)
        return 84;
    buffer = malloc(sizeof(char) * buf.st_size);
    fd = open(arv[1], O_RDONLY);
    read(fd, buffer, buf.st_size);
    if (S_ISREG(buf.st_mode)) {
        if (error_gest_ext(buffer, buf) == 84)
            return 84;
    } else
        return 84;
    return 0;
}

int main(int arc, char **arv)
{
    int return_error = 0;

    if (arc < 2 || arc > 3)
        return 84;
    if (arc == 2) {
        if (error_gest_arc2(arv) == 84)
            return 84;
        else
            bsq(arv[1]);
    }
    if (arc == 3) {
        return_error = main_extension(arv);
        if (return_error == 84)
            return 84;
        generator_map(arv);
    }
}
