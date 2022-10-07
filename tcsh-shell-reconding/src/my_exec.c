/*
** EPITECH PROJECT, 2021
** mysh1
** File description:
** my_exec : use execve
*/

#include "mysh.h"

void check_wait(int status)
{
    if (wait(&status) == -1)
        my_put_error("error\n");
}

void simple_exec(char **c, char **env)
{
    int pid = 0;
    int st = 0;

    if (pid == -1)
        my_put_error("error pid\n");
    if (access(c[0], X_OK) == -1) {
        c[0][str_len(c[0]) - 1] = c[0][str_len(c[0]) - 1] == '/'
            ? '\0' : c[0][str_len(c[0]) - 1];
        my_put_error(my_strcat(": Command not found.\n", c[0]));
    }
    else if ((pid = fork()) == 0)
        execve(c[0], c, env);
    else
        check_wait(st);
}

void my_exec(char *cmd, exec_t *exe)
{
    char **cmd_tab = clean_tab(ft_word_tab(cmd, ' '));
    int pid = fork();
    int status = 0;

    if (pid == -1)
        my_put_error("error pid\n");
    if (pid == 0)
        execve(exe->path, cmd_tab, exe->env);
    else
        check_wait(status);
}
