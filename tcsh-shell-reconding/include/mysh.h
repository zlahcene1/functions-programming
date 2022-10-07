/*
** EPITECH PROJECT, 2020
** headerz
** File description:
** my_ls
*/

#ifndef MY_LS_
#define MY_LS_

/************** INCLUDES ********************/

#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <unistd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"

/************* boolEAN *******************/

typedef struct exe
{
    char **env;
    char *path;
    char *name;
}exec_t;

/************** BEFORE RUN ****************/

char **cl_tab(char **tab);
void do_redirect2(char *cmd, char **env);
bool check_redirect(char *cmd, char **env);
char *clear_str(char *str);
void do_redirect(char *cmd, char **env);
char *find_path(char **env);
char **clean_tab(char **tab);
int my_mysh(char **env);
char **cd_oldpwd(char *cmd, char **env);
char *take_input(char *cmd, char **env);
int my_pwd(char *cmd, char **env);
int there_is_an_error(int ac, char **av);
char **fill_empty_env(char **cpy);
char **repare_env(char **env);
char **creat_cpy_env(char **env);

/************** FUNCTIONS *****************/

char **do_cmd(char *cmd, char **env);
void my_exec(char *cmd, exec_t *exe);
void put_prompt(char **env);
char *get_cwd(void);
int counter_env(char **env);
char **execute_function(char *cmd, char **env);

/*********** EXEC  FUNCTIONS **************/

char *parse_cmd(char *cmd);
char **format_my_tab(char **tab, int count);
char *parser(char *SRC, int n);
char **ft_word_tab(char *str, char c);
int ft_count_string(char *str, char c);
bool cmd_in_path(char **word_path, char *cmd_p);

/************* MUST HAVE *****************/

char **my_cd(char *cmd, char **env);
int my_exit(char *cmd, char **env);
char **my_env(char **env, char *cmd);
char **my_setenv(char **env, char *cmd);
char **my_unsetenv(char **env, char *cmd);

/************* SETENV ********************/

char *setenv_parser(char *cmd, char *dest);
char *setenv_string(char *cmd, int i, char *string);
char *fill_env(char *cmd, char *dest);
char **fill_cpy(char **env, char **cpy, char *cmd);
bool check_bin(char *cmd, char **env, exec_t *exe);
void simple_exec(char **cmd_tab, char **env);

#define MACRO2 "S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR"
#define MACRO1 O_WRONLY | O_TRUNC | O_CREAT

#endif
