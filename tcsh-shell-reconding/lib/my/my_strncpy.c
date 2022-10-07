/*
** EPITECH PROJECT, 2020
** hkfjg
** File description:
** hgfd
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i; i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
