/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** all must have
*/

#include "mysh.h"

char *get_cwd(void)
{
    char *cwd = NULL;
    int len = 0;

    cwd = getcwd(cwd, 4096);
    len = str_len(cwd);
    cwd[len] = '/';
    cwd[len + 1] = '\0';
    return cwd;
}

int my_exit(char *cmd, char **env)
{
    my_putstr("exit\n");
    return -2;
}

int my_pwd(char *cmd, char **env)
{
    char *pwd = NULL;

    my_putstr(getcwd(pwd, 4096));
    my_putchar('\n');
    return 0;
}

char **my_env(char **env, char *cmd)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return env;
}
