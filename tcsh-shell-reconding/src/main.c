/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** main.c
*/

#include "mysh.h"

char **repare_env(char **env)
{
    char **cpy = 0;

    if (env[0] == 0) {
        cpy = malloc(sizeof(char *) * 2);
        cpy[0] = str_dup(get_cwd());
        cpy[1] = str_dup("PATH=");
        return cpy;
    } else
        return env;
}

char **creat_cpy_env(char **env)
{
    char **dest = malloc(sizeof(char *) * (counter_env(env) + 10));
    int i = 0;

    for (; env[i] != NULL; i++)
        dest[i] = str_dup(env[i]);
    dest[i] = NULL;
    return repare_env(dest);
}

int main(int ac, char **av, char **env)
{
    return ac == 1 ? my_mysh(creat_cpy_env(env)) : 84;
}
