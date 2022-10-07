/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    for (i; dest[i] != '\0'; i++);
    for (j; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return (dest);
}
