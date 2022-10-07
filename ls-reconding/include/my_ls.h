/*
** EPITECH PROJECT, 2020
** headerz
** File description:
** my_ls
*/

#ifndef MY_LS_
#define MY_LS_

/************** INCLUDES ********************/

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <unistd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/************** FUNCTIONS *****************/

int is_flag(int ac, char **av, char *str);
void *my_memset (void * s, int c, int n);
void droit(char *nom, struct stat s, char *tab_right);
char *time_parser(char *str);
void all_print(struct stat s, struct dirent *directory, char *tab_right);
char *where_is_my_repo(int ac, char **av);
void check_args(int ac, char **av);
int flag_error(char *str);
void droit(char *nom, struct stat s, char *tab_right);
void list(int ac, char **av);

#endif
