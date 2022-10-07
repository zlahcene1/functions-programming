/*
** EPITECH PROJECT, 2020
** smtrdup_my
** File description:
** d08
*/

#include <stdlib.h>

int str_len(char const *str);

char *my_strcpy(char *dest, char const *src);

char *str_dup(char const *src)
{
    char *dest = malloc(sizeof(char) + (str_len(src) + 1));

    return (my_strcpy(dest, src));
}
