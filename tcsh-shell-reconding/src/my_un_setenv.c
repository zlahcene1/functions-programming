/*
** EPITECH PROJECT, 2021
** mysh 1
** File description:
** setenv and unsetenv
*/

#include "mysh.h"

int counter_env(char **env)
{
    int count = 0;

    for (int i = 0; env[i] != NULL; i++, count++);
    return count;
}

char **my_unsetenv(char **env, char *cmd)
{
    char **cpy = malloc(sizeof(char *) * (counter_env(env)) + 1);
    int counter = ft_count_string(cmd, ' ');
    int j = 0;

    if (str_len(cmd) < 9) {
        my_put_error("unsetenv: Too few arguments.\n");
        return env;
    }
    cmd += 9;
    for (int i = 0; env[i] != NULL; i++) {
        if (str_ncmp(env[i], cmd, str_len(cmd)) == 0)
            continue;
        else {
            cpy[j] = str_dup(env[i]);
            j += 1;
        }
    }
    cpy[j + 1] = NULL;
    return cpy;
}
