/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** all parser
*/

#include "my.h"
#include "my_ls.h"

void droit(char *nom, struct stat s, char *tab_right)
{
    my_memset(tab_right, 0, 10);
    if (S_ISREG(s.st_mode))
        tab_right[0] = '-';
    else if (S_ISDIR(s.st_mode))
        tab_right[0] = 'd';
    else if (S_ISLNK(s.st_mode))
        tab_right[0] = 'l';
    s.st_mode & S_IRUSR?my_strcat(tab_right, "r"):my_strcat(tab_right, "-");
    s.st_mode & S_IWUSR?my_strcat(tab_right, "w"):my_strcat(tab_right, "-");
    s.st_mode & S_IXUSR?my_strcat(tab_right, "x"):my_strcat(tab_right, "-");
    s.st_mode & S_IRGRP?my_strcat(tab_right, "r"):my_strcat(tab_right, "-");
    s.st_mode & S_IWGRP?my_strcat(tab_right, "w"):my_strcat(tab_right, "-");
    s.st_mode & S_IXGRP?my_strcat(tab_right, "x"):my_strcat(tab_right, "-");
    s.st_mode & S_IROTH?my_strcat(tab_right, "r"):my_strcat(tab_right, "-");
    s.st_mode & S_IWOTH?my_strcat(tab_right, "w"):my_strcat(tab_right, "-");
    s.st_mode & S_IXOTH?my_strcat(tab_right, "x"):my_strcat(tab_right, "-");
}

void list(int ac, char **av)
{
    struct stat s;
    DIR* rep = opendir(where_is_my_repo(ac, av));
    struct dirent *directory = NULL;
    char tab_right[10];

    if (rep == NULL)
        exit(84);
    while ((directory = readdir(rep)) != NULL) {
        lstat(directory->d_name, &s);
        droit(directory->d_name, s, tab_right);
        if (directory->d_name[0] != '.' && av[1][2] != 'a')
            all_print(s, directory, tab_right);
        if (av[1][2] == 'a')
            all_print(s, directory, tab_right);
    }
    if (closedir(rep) == -1)
        exit(84);
    exit(0);
}
