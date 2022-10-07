/*
** EPITECH PROJECT, 2020
** d06
** File description:
** 1st letter in maj
*/

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    str = my_strlowcase(str);
    str[0] -= 32;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i - 1] == ' ' && str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return (str);
}
