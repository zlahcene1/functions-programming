/*
** EPITECH PROJECT, 2020
** square root
** File description:
** d05
*/

int my_compute_square_root(int nb)
{
    int res = 0;

    if (nb < 0)
        return (0);
    while (res * res < nb)
        res++;
    if (res == nb)
        return (res);
    if (res > nb)
        return (0);
}
