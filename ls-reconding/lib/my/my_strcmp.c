/*
** EPITECH PROJECT, 2020
** kjdks
** File description:
** hgfd
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int tmp = 0;

    while (1 == 1) {
        if (s1[i] != s2[i]) {
            tmp = s1[i] - s2[i] < 0 ? -1 : 1;
            return (tmp);
        }
        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        i++;
    }
}
