/*
** EPITECH PROJECT, 2021
** mysh1
** File description:
** creat an array with a simple string
*/

#include "mysh.h"

int count_char(char *str, int index, char c)
{
    int counter = 0;

    for (index; str[index] != c && str[index] != '\0'; index++, counter++);
    return counter;
}

int ft_count_string(char *str, char c)
{
    int count_s = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count_s++;
    }
    return count_s;
}

char **simple_string(char **tab, char *str, int count_s)
{
    tab = malloc(sizeof(char *) * (count_s + 1));
    tab[0] = malloc(sizeof(char) + str_len(str) + 1);
    tab[0] = str;
    tab[1] = NULL;
    return tab;
}

char **ft_word_tab(char *str, char c)
{
    char **tab = NULL;
    int  count_s = ft_count_string(str, c);
    int count_c = 0;
    int x = 0;

    if (count_s == 1)
        return simple_string(tab, str, count_s);
    tab = malloc(sizeof(char *) * (count_s + 1));
    for (int i = 0, y = 0; x < count_s; x++, i++) {
        y = 0;
        count_c = count_char(str, i, c);
        tab[x] = malloc(sizeof(char) + count_c + 1);
        for (; str[i] != c && str[i] != '\0'; i++, y++) {
            tab[x][y] = str[i];
        }
        tab[x][y] = '/';
        tab[x][y + 1] = '\0';
    }
    tab[x] = NULL;
    return (tab);
}
