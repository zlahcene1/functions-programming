/*
** EPITECH PROJECT, 2020
** okok
** File description:
** okok
*/

char *my_strdup(char const *src);

char *my_strupcase(char const *str)
{
    char *cpy = my_strdup(str);

    for (int i = 0; cpy[i] != '\0'; i++) {
        if (cpy[i] >= 'a' && cpy[i] <= 'z')
            cpy[i] = cpy[i] - ' ';
    }
    return (cpy);
}
