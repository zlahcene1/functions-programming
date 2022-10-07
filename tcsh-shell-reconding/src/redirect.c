/*
** EPITECH PROJECT, 2021
** minishell 2
** File description:
** redict
*/

#include "mysh.h"

char *file_name(char *cmd)
{
    int idx = 0;
    char *cpy = str_dup(cmd);

    for (; cmd[idx] != '>'; idx++);
    cpy += (idx + 1);
    return clear_str(clean_str(cpy));
}

char *parse_redirect(char *cmd)
{
    int idx = 0;
    char *cpy = NULL;

    for (; cmd[idx] != '>'; idx++);
    cpy = malloc(sizeof(char) * (idx + 1));
    for (int i = 0; i < idx; i++)
        cpy[i] = cmd[i];
    cpy[idx] = '\0';
    return clear_str(clean_str(cpy));
}

char **cl_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        tab[i] = str_dup(clear_str(tab[i]));
    return tab;
}

void do_redirect(char *cmd, char **env)
{
    char *file = file_name(cmd);
    char *ft = parse_redirect(cmd);
    char **ft_tab = NULL;
    exec_t *exe = malloc(sizeof(exec_t));
    int fd = open(file, MACRO1, MACRO2);

    ft_tab = cl_tab(clean_tab(ft_word_tab(ft, ' ')));
    if (fd == -1)
        return;
    else if (!check_bin(ft_tab[0], env, exe))
        my_put_error(my_strcat(": Command not found.\n", ft_tab[0]));
    else
        if (fork() == 0) {
            dup2(fd, 1);
            execve(exe->path, ft_tab, env);
        }
    close(fd);
    free(exe);
}

bool check_redirect(char *cmd, char **env)
{
    for (int i = 0; cmd[i] != '\0'; i++) {
        if (cmd[i] == '>') {
            do_redirect(cmd, env);
            return true;
        }
        if (cmd[i] == '<') {
            do_redirect2(cmd, env);
            return true;
        }
    }
    return false;
}
