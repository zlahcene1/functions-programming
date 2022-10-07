/*
** EPITECH PROJECT, 2020
** d05
** File description:
** trouver plus petit prime
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    for (int i = 1; i < 2147483647; i++) {
        if (my_is_prime(nb + i) == 1)
            return (nb + i);
    }
    return (0);
}
