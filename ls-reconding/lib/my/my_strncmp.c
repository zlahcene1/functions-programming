/*
** EPITECH PROJECT, 2020
** kjndg
** File description:
** mjfdsh
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int tmp = 0;

    while (i < n) {
        if (s1[i] != s2[i]) {
            tmp = s1[i] > s2[i] ? -1 : 1;
            return (tmp);
        }
        i++;
    }
    return (0);
}
