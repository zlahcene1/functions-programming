/*
** EPITECH PROJECT, 2020
** okok
** File description:
** d05
*/

int case_1(int nb)
{
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}

int case_2(int nb)
{
    for (int i = -2; i > nb; i--) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}

int check_sign(int nb)
{
    if (nb == 1 || nb == 0 || nb == 2)
        return (2);
    if (nb > 0)
        return (1);
    return (0);
}

int my_is_prime(int nb)
{
    if (check_sign(nb) == 1)
        return (case_1(nb));
    if (check_sign(nb) == 2)
        return (0);
    else
        return (case_2(nb));
}
