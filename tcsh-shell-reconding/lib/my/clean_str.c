/*
** EPITECH PROJECT, 2021
** clean str
** File description:
** lib
*/

#include <stddef.h>
#include <stdlib.h>

int str_len(char const *str);

char *clear_str(char *str)
{
    int idx = 0;
    for (int i = str_len(str); str[i] == ' '; i--) {
        str[i] = '\0';
        if (str[idx] == ' ') {
            str += 1;
            idx++;
        }
    }
    return str;
}

char *clean_str(char *str)
{
    char *s = malloc(sizeof(char) * (str_len(str) + 1));
    char *tmp = NULL;
    int i = 0;
    int j = 0;

    if (s == NULL)
        return NULL;
    while ((str[0] == ' ' || str[0] == '\t') && str[0] != '\0')
        str++;
    while (str[i] != '\0') {
        for (; str[i] != ' ' && str[i] != '\t' && str[i] != '\0'; i++)
            s[j++] = str[i];
        for (; str[i] == ' ' || str[i] == '\t'; i++);
        if (str[i] == '\0')
            break;
        s[j++] = ' ';
    }
    s[j] = '\0';
    return s;
}
