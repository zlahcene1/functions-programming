/*
** EPITECH PROJECT, 2020
** strdup
** File description:
** d08
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    return (my_strcpy(dest, src));
}
