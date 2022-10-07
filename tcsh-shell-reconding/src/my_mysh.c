/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** core function
*/

#include "mysh.h"

void quit_program(char *cmd, char **env)
{
    for (int i = 0; env[i]; i++)
        free(env[i]);
    free(env);
    free(cmd);
    exit(0);
}

char *take_input(char *cmd, char **env)
{
    size_t len;

    if (getline(&cmd, &len, stdin) <= 0)
        quit_program(cmd, env);
    cmd = clean_str(cmd);
    cmd[str_len(cmd) - 1] = '\0';
    if (str_cmp(cmd, "\0") == 0)
        return cmd;
    return cmd;
}

char **do_cmd(char *cmd, char **env)
{
    if (str_ncmp("cd", cmd, 2) == 0)
        return my_cd(cmd, env);
    else
        return execute_function(cmd, env);
}

int my_mysh(char **env)
{
    char *cmd = NULL;
    char **cmd_tab = NULL;

    my_putstr("$> ");
    cmd = take_input(cmd, env);
    cmd_tab = ft_word_tab(cmd, ';');
    if (str_cmp(cmd, "\0") == 0)
        my_mysh(env);
    for (int i = 0; cmd_tab[i]; i++) {
        if (cmd_tab[i][str_len(cmd_tab[i]) - 1] == '/')
            cmd_tab[i][str_len(cmd_tab[i]) - 1] = '\0';
        cmd_tab[i] = clean_str(cmd_tab[i]);
        cmd_tab[i] = clear_str(cmd_tab[i]);
        if (str_cmp(cmd_tab[i], "") == 0)
            continue;
        env = do_cmd(cmd_tab[i], env);
    }
    my_mysh(env);
}
