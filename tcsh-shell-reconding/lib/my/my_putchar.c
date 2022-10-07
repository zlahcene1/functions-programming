/*
** EPITECH PROJECT, 2020
** lib
** File description:
** putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int is_alphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            if ((str[i] < 'a' || str[i] > 'z') && str[i] != ' ')
                if (str[i] != '/')
                    return -1;
    return 0;
}
