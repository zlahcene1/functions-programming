/*
** EPITECH PROJECT, 2021
** mysh1
** File description:
** recode cd function
*/

#include "mysh.h"

char *get_where(char *cmd)
{
    char *CPY = NULL;

    CPY = str_dup(cmd);
    CPY += 3;
    return CPY;
}

char *get_home(char **env)
{
    int index = 0;
    char *dest = NULL;

    for (int i = 0; env[i] != NULL; i++)
        if (str_ncmp(env[i], "HOME=", 5) == 0)
            index = i;
    dest = env[index];
    dest += 5;
    return dest;
}

char **cd_oldpwd(char *cmd, char **env)
{
    char *cpy = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        if (str_ncmp(env[i], "OLDPWD", 6) == 0) {
            cpy = str_dup(env[i]);
            cpy += 7;
            env = my_unsetenv(env, "unsetenv OLDPWD");
            env = my_setenv(env, my_strcat(get_cwd(), "setenv OLDPWD "));
            chdir(cpy);
            return env;
        }
    }
    return env;
}

char **cd_error(char **env, char *where)
{
    if (errno == EACCES)
        my_put_error("Permission denied.\n");
    else if (errno == ENOTDIR || errno == ENOENT)
        my_put_error(my_strcat(": Not a directory.\n", where));
    else
        return env;
}

char **my_cd(char *cmd, char **env)
{
    char *where = get_where(cmd);
    char *cwd = get_cwd();
    int tmp = 1;

    if (str_cmp(cmd, "cd /") == 0) {
        env = my_unsetenv(env, "unsetenv OLDPWD");
        env = my_setenv(env, my_strcat(get_cwd(), "setenv OLDPWD "));
        chdir("/");
        return env;
    }
    if (str_cmp(cmd, "cd-") == 0 || str_cmp(cmd, "cd -") == 0)
        return cd_oldpwd(cmd, env);
    env = my_unsetenv(env, "unsetenv OLDPWD");
    env = my_setenv(env, my_strcat(get_cwd(), "setenv OLDPWD "));
    tmp = str_ncmp(cmd, "cd ~", 4) == 0 || str_cmp(cmd, "cd") == 0
        ? chdir(get_home(env)) : chdir(my_strcat(where, cwd));
    tmp = str_ncmp(cmd, "cd /", 4) == 0 ? chdir(where) : tmp;
    return tmp == -1 ? cd_error(env, where) : env;
}
