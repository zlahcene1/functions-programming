/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_memset
*/

void *my_memset(void * s, int c, int n)
{
    char *stock = s;

    for (int i = 0; i < n; i++)
        stock[i] = (char) c;
    return s;
}
