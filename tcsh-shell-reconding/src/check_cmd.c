/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** function who check if your input is correctly
*/

#include "mysh.h"

char **clean_tab(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        if (tab[i][str_len(tab[i]) - 1] == '/')
            tab[i][str_len(tab[i]) - 1] = '\0';
    }
    return tab;
}

char *find_path(char **env)
{
    char *tmp = NULL;

    for (int i = 0; env[i]; i++)
        if (str_ncmp("PATH=", env[i], 5) == 0) {
            tmp = str_dup(env[i]);
            tmp += 5;
            return tmp;
        }
    return NULL;
}

bool check_bin(char *cmd, char **env, exec_t *exe)
{
    char **cmd_tab = clean_tab(ft_word_tab(cmd, ' '));
    char *path = find_path(env);
    char **path_tab = NULL;

    if (str_ncmp("/", cmd_tab[0], 1) == 0) {
        simple_exec(cmd_tab, env);
        my_mysh(env);
    }
    exe->name = str_dup(cmd_tab[0]);
    path_tab = ft_word_tab(path, ':');
    for (int i = 0; path_tab[i]; i++) {
        if (access(my_strcat(cmd_tab[0], path_tab[i]), X_OK) != -1) {
            exe->path = str_dup(my_strcat(cmd_tab[0], path_tab[i]));
            exe->env = env;
            return true;
        }
    }
    return false;
}
