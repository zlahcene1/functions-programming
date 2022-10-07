/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** parser
*/

#include "mysh.h"

char *parser(char *SRC, int n)
{
    char *dest = NULL;
    int index = 0;
    int count = 0;

    for (int i = n; SRC[i] != '\0'; i++, count++);
    dest = malloc(sizeof(char) + count + 2);
    for (int i = n; SRC[i] != '\0'; i++, index++)
        dest[index] = SRC[i];
    dest[index] = '\0';
    return dest;
}

char *parse_cmd(char *cmd)
{
    char *dest = NULL;
    int count = 0;

    for (int i = 0; cmd[i] != ' ' && cmd[i] != '\0'; i++, count++);
    if (count == str_len(cmd))
        return cmd;
    dest = malloc(sizeof(char) + count + 1);
    for (int i = 0; cmd[i] != ' '; i++)
        dest[i] = cmd[i];
    dest[count] = '\0';
    return dest;
}

char **format_my_tab(char **tab, int count)
{
    if (tab[0][str_len(tab[0]) - 1] == '/' && tab[0] != NULL) {
        for (int i = 0; i != count; i++)
            tab[i] = my_strncpy(tab[i], tab[i], str_len(tab[i]) - 1);
    }
    return tab;
}
