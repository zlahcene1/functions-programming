/*
** EPITECH PROJECT, 2020
** revstr
** File description:
** revstr
*/

int str_len(char *str);

void my_swap(int *a, int *b);

char *my_revstr(char *str)
{
    int j = str_len(str) - 1;
    char tmp = str[0];

    for (int i = 0; i < j; i++) {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        j -= 1;
    }
    return (str);
}
