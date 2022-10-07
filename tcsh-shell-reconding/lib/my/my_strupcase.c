/*
** EPITECH PROJECT, 2020
** okok
** File description:
** okok
*/

char *str_dup(char const *src);

char *my_strupcase(char const *str)
{
    char *cpy = str_dup(str);

    for (int i = 0; cpy[i] != '\0'; i++) {
        if (cpy[i] >= 'a' && cpy[i] <= 'z')
            cpy[i] = cpy[i] - ' ';
    }
    return (cpy);
}
