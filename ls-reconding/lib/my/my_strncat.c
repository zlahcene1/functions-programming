/*
** EPITECH PROJECT, 2020
** lib
** File description:
** ncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    for (i; dest[i] != '\0'; i++);
    for (j; src[j] != '\0' && j < nb; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return (dest);
}
