/*
** EPITECH PROJECT, 2020
** all prints
** File description:
** ll
*/

#include "printf.h"

void char_traitement(va_list list, char *str, int pos, ...)
{
    if (str[pos + 1] == 's')
        my_putstr(va_arg(list, char *));
    if (str[pos + 1] == 'c')
        my_putchar(va_arg(list, int));
}

int nb_traitement(va_list list, char *str, int pos, ...)
{
    if (str[pos + 1] == 'd' || str[pos + 1] == 'i')
        my_put_nbr(va_arg(list, int));
    if (str[pos + 1] == 'l' || str[pos + 2] == 'd') {
        my_put_nbr(va_arg(list, long int));
        pos += 1;
    }
    if (str[pos + 1] == 'u')
        my_put_nbr(va_arg(list, unsigned int));
    return (pos);
}

void hexa_traitement(va_list list, char *str, int pos)
{
    if (str[pos + 1] == 'x')
        print_hexa(va_arg(list, int));
    if (str[pos + 1] == 'X')
        print_hexa_maj(va_arg(list, int));
}

void bases_checker(va_list list, char *str, int pos)
{
    if (str[pos + 1] == 'o')
        print_octal(va_arg(list, int));
    if (str[pos + 1] == 'b')
        print_binary(va_arg(list, int));
    if (str[pos + 1] == 'p')
        print_pointer(va_arg(list, int));
    hexa_traitement(list, str, pos);
}
