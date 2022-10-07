/*
** EPITECH PROJECT, 2020
** putstr
** File description:
** d4
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}

void my_put_nbr(unsigned int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb / 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}
