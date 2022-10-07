/*
** EPITECH PROJECT, 2021
** my sh 1
** File description:
** built in or execve
*/

#include "mysh.h"

int is_here(char *cmd, char **ft)
{
    if (str_cmp(cmd, "exit") == 0)
        return 0;
    if (str_cmp(cmd, "pwd") == 0)
        return 1;
    return -1;
}

int is_here2(char *cmd, char **ft)
{
    for (int i = 0; ft[i] != 0; i++) {
        if (str_ncmp("env", cmd, 3) == 0)
            return 2;
        if (str_ncmp(ft[i], cmd, 5) == 0)
            return i;
    }
    return -1;
}

int verify_builtings(char *cmd, int tmp, char **env)
{
    char *f1[3] = {"exit", "pwd", 0};
    int (*ptr1[2]) (char *, char **) = {my_exit, my_pwd};

    tmp = is_here(cmd, f1);
    tmp = tmp >= 0 ? (*ptr1[tmp]) (cmd, env) : -1;
    if (tmp == -2)
        return -2;
    return tmp;
}

char **update_env(char **env)
{
    char *pwd = get_cwd();
    int idx = 0;

    for (int i = 0; env[i] != NULL; i++)
        if (str_ncmp("PWD=", env[i], 4) == 0)
            idx = i;
    env[idx] = my_strcat(pwd, "PWD=");
    return env;
}

char **execute_function(char *cmd, char **env)
{
    exec_t *exe = malloc(sizeof(exe));
    int tmp = verify_builtings(cmd, tmp, env);
    char *f2[4] = {"setenv", "unsetev", "env", 0};
    char** (*ptr2[3]) (char**, char*) = {my_setenv, my_unsetenv, my_env};

    if (check_redirect(cmd, env))
        return env;
    if (tmp == -2)
        exit(0);
    if (tmp == -1) {
        tmp = tmp == -1 ? is_here2(cmd, f2) : - 1;
        env = tmp >= 0 ? (*ptr2[tmp]) (env, cmd) : update_env(env);
        if (tmp == -1 && check_bin(cmd, env, exe))
            my_exec(cmd, exe);
        else if (tmp == -1)
            my_put_error(my_strcat(": Command not found.\n", exe->name));
        else
            return env;
    }
    return env;
}
