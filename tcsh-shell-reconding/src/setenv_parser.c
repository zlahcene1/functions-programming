/*
** EPITECH PROJECT, 2021
** my sh 1
** File description:
** setenv parser
*/

#include "mysh.h"

char *setenv_parser(char *cmd, char *dest)
{
    int i = 0;

    for (; cmd[i] != ' ' && i != str_len(cmd); i++);
    dest = malloc(sizeof(char) + (1 + i));
    i = 0;
    for (; cmd[i] != ' ' && i != str_len(cmd); i++)
        dest[i] = cmd[i];
    dest[i] = '\0';
    return dest;
}

char *setenv_string(char *cmd, int i, char *string)
{
    int j = 0;
    int count = i;

    for (; count != str_len(cmd); count++);
    string = malloc(sizeof(char) + (count + 1));
    for (; i != str_len(cmd); i++, j++)
        string[j] = cmd[i];
    string[j] = '\0';
    return string;
}

char *fill_env(char *cmd, char *dest)
{
    char *name = setenv_parser(cmd, name);
    char *str = setenv_string(cmd, str_len(name) + 1, str);

    dest = my_strcat("=", name);
    return my_strcat(str, dest);
}

char **fill_cpy(char **env, char **cpy, char *cmd)
{
    int j = 0;
    char *name = setenv_parser(cmd, name);

    for (int i = 0, idx = 0; env[i] != NULL; i++) {
        if (str_ncmp(env[i], name, str_len(name)) != 0) {
            cpy[j] = str_dup(env[i]);
            j += 1;
        }
        else
            idx = i;
    }
    cpy[j] = fill_env(cmd, cpy[j]);
    cpy[j + 1] = NULL;
    return cpy;
}
