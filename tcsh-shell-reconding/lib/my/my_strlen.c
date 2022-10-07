/*
** EPITECH PROJECT, 2020
** lib
** File description:
** mystrlen
*/

int str_len(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
