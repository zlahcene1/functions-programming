/*
** EPITECH PROJECT, 2020
** kjndg
** File description:
** mjfdsh
*/

int str_ncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int tmp = 0;

    while (i < n) {
        if (s1[i] != s2[i])
            return -1;
        i++;
    }
    return (0);
}
