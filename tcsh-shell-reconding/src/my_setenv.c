/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** setenv
*/

#include "mysh.h"

bool no_argument(char *cmd, char **env)
{
    if (str_cmp(cmd, "setenv") == 0) {
        my_env(env, cmd);
        return true;
    } else
        return false;
}

char **do_copy(char **cpy, char **env, char *name, char *cmd)
{
    int idx = 0;
    int c = 0;

    for (; env[idx] != NULL; idx++)
        cpy[idx] = str_dup(env[idx]);
    cpy[idx] = str_dup(my_strcat("=", name));
    cpy[idx] = str_dup(my_strcat(cmd, cpy[idx]));
    cpy[idx + 1] = NULL;
    return cpy;
}

char **sp(char **env, char *cmd, char *name, int i)
{
    char **cpy = malloc(sizeof(char *) * (counter_env(env) + 10));

    if (str_len(name) == str_len(cmd)) {
        env[i] = str_dup(my_strcat("=", name));
        return env;
    }
    else {
        cmd += str_len(name) + 1;
        env = my_unsetenv(env, my_strcat(name, "unsetenv "));
        return do_copy(cpy, env, name, cmd);
    }
    return env;
}

char **my_setenv(char **env, char *cmd)
{
    char **cpy = NULL;
    int counter = ft_count_string(cmd, ' ');
    char *name = NULL;

    if (no_argument(cmd, env))
        return env;
    cmd += 7;
    name = setenv_parser(cmd, name);
    for (int i = 0; env[i]; i++)
        if (str_ncmp(env[i], name, str_len(name)) == 0)
            return sp(env, cmd, name, i);
    cmd += str_len(name) + 1;
    cpy = malloc(sizeof(char *) * (counter_env(env) + 10));
    return do_copy(cpy, env, name, cmd);
}
