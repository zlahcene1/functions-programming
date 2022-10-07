/*
** EPITECH PROJECT, 2021
** lin
** File description:
** write error outpout
*/

#include <unistd.h>

void putchar_error(char c)
{
    write(2, &c, 1);
}

void my_put_error(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        putchar_error(str[i]);
}
