/*
** EPITECH PROJECT, 2020
** revstr
** File description:
** revstr
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int j = my_strlen(str) - 1;
    char tmp = str[0];

    for (int i = 0; i < j; i++) {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        j -= 1;
    }
    return (str);
}
