/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** utils
*/

#include "my.h"
#include "my_ls.h"

char *time_parser(char *str)
{
    char *tmp = malloc(sizeof(char) + (my_strlen(str) - 15));
    int x = 0;

    for (int i = 4; i != my_strlen(str) - 9; i++, x++)
        tmp[x] = str[i];
    tmp[x] = '\0';
    return (tmp);
}

void all_print(struct stat s, struct dirent *directory, char *tab_right)
{
    my_putstr(tab_right);
    my_putchar(' ');
    my_put_nbr((int)s.st_nlink);
    my_putchar(' ');
    my_putstr(getgrgid(s.st_gid)->gr_name);
    my_putchar(' ');
    my_putstr(getpwuid(s.st_uid)->pw_name);
    my_putchar(' ');
    my_put_nbr((int)s.st_size);
    my_putchar(' ');
    my_putstr(time_parser(ctime(&s.st_ctime)));
    my_putchar(' ');
    my_putstr(directory->d_name);
    my_putchar('\n');
}

char *where_is_my_repo(int ac, char **av)
{
    char *tmp = NULL;
    int i = 1;

    for (; i < ac; i++) {
        if (av[i][0] != '-')
            return (av[i]);
    }
    return (".\0");
}
