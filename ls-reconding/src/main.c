/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** main.c
*/

#include "my.h"
#include "my_ls.h"

void simple_outpout(int ac, char **av)
{
    DIR *rep =  opendir(where_is_my_repo(ac, av));
    struct dirent *directory = NULL;

    if (rep == NULL)
        exit(84);
    while ((directory = readdir(rep)) != NULL) {
        if (directory->d_name[0] != '.') {
            my_putstr(directory->d_name);
            my_putchar(' ');
        }
    }
    my_putchar ('\n');
    exit(0);
}

int main(int ac, char **av)
{
    if (ac > 1) {
        check_args(ac, av);
        if (av[1][0] == '-' && av[1][1] == 'l')
            list(ac, av);
        else
            simple_outpout(ac, av);
    } else
        simple_outpout(ac, av);
    return (0);
}
