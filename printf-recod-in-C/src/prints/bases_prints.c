/*
** EPITECH PROJECT, 2020
** put
** File description:
** hexa
*/

#include "printf.h"

void print_hexa(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb / 16)
        print_hexa(nb / 16);
    my_putchar(BASE_16[nb % 16]);
}

void print_hexa_maj(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb / 16)
        print_hexa_maj(nb / 16);
    my_putchar(BASE_MAJ[nb % 16]);
}

void print_octal(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb / 8)
        print_octal(nb / 8);
    my_putchar(BASE_8[nb % 8]);
}

void print_binary(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb / 2)
        print_binary(nb / 2);
    my_putchar(nb % 2 + '0');
}

void print_pointer(int nb)
{
    if (nb == 0)
        my_putstr("(nul)");
    else {
        my_putstr("0x");
        print_hexa(nb);
    }
}
