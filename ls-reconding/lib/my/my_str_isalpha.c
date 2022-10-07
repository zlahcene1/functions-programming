/*
** EPITECH PROJECT, 2020
** is alpha
** File description:
** d06
*/

char *my_strupcase(char const *str);

int my_str_isalpha(char const *str)
{
    char *cpy = my_strupcase(str);

    for (int i = 0; cpy[i] != '\0'; i++) {
        if (cpy[i] < 'A' || cpy[i] > 'Z')
            return (0);
    }
    return (1);
}
