/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** errors
*/

#include "my.h"
#include "my_ls.h"

int flag_error(char *str)
{
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] != 'l' && str[i] != 'R' && str[i] != 'd' && str[i] != 't')
            exit (84);
    }
}

void check_args(int ac, char **av)
{
    if (av[1][0] == '-')
        flag_error(av[1]);
}
