/*
** EPITECH PROJECT, 2020
** kjdks
** File description:
** hgfd
*/

int str_len(char *str);

int str_cmp(char *s1, char *s2)
{
    for (; *s1 && *s2 && *s1 == *s2; s1++, s2++);
    return *s1 - *s2;
}
