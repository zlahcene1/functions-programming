/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_strcat
*/

#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 4096);

    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    for (int j = 0; dest[j] != '\0'; i++, j++)
        str[i] = dest[j];
    str[i] = '\0';
    return str;
}
