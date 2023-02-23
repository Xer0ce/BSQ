/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** cat
*/

int mystrlen(char const *str)
{
    int compteur = 0;
    while (str[compteur] != '\0') {
        compteur++;
    }
    return (compteur);
}

char *my_strcat(char *dest, const char *src)
{
    int dest_len = mystrlen(dest);
    int i;

    for (i = 0 ;src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}
