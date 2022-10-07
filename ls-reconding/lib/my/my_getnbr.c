/*
** EPITECH PROJECT, 2020
** getnbr
** File description:
** d04
*/

int my_getnbr(char *str)
{
    int a = 0;
    int b = 0;
    int count = 1;

    if (str[0] == '-')
        a++;
    while (str[a] != '\0') {
        if (str[a] < '0' || str[a] > '9' || count > 9) {
            return (0);
        }
        b = b + str[a] - 48;
        b = b * 10;
        a++;
        count++;
    }
    if (str[0] == '-')
        return (-1 * (b / 10));
    return (b / 10);
}
