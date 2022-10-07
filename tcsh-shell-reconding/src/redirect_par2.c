/*
** EPITECH PROJECT, 2021
** mysh 2
** File description:
** redirection
*/

#include "mysh.h"

char *file_name2(char *cmd)
{
    int idx = 0;
    char *cpy = NULL;

    for (; cmd[idx] != '<'; idx++);
    cpy = malloc(sizeof(char) * (idx + 1));
    cpy = my_strncpy(cpy, cmd, idx);
    return clear_str(clean_str(cpy));
}

char *parse_redirect2(char *cmd)
{
    int idx = 0;
    int len = 0;
    int i = 0;

    for (; cmd[len] != '<'; len++, idx++);
    idx++;
    for (; cmd[len] != '\0'; len++);
    cmd += idx + 1;
    return clear_str(clean_str(cmd));
}

void do_redirect2(char *cmd, char **env)
{
    char *file = file_name2(cmd);
    char *ft = parse_redirect2(cmd);
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
