/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** isneg
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}
