/*
** EPITECH PROJECT, 2020
** my
** File description:
** printf
*/

#include "printf.h"

void double_modulo(char *str, int pos)
{
    if (str[pos] == '%' && str[pos++] == '%')
        my_putchar('%');
    return;
}

int modulo_checker(char *str, int pos, va_list list)
{
    if (str[pos] == '%') {
        pos = nb_traitement(list, str, pos);
        char_traitement(list, str, pos);
        bases_checker(list, str, pos);
        pos += 1;
    }
    else
        my_putchar(str[pos]);
    return (pos);
}

void my_printf(char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int pos = 0; str[pos]; pos += 1) {
        double_modulo(str, pos);
        pos = modulo_checker(str, pos, list);
    }
    va_end(list);
}
