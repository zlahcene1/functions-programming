/*
** EPITECH PROJECT, 2020
** printf.h
** File description:
** all headers
*/

#ifndef PRINTF_H_
#define PRINTF_H_

/*****************ALL LIB****************/

#include "stdarg.h"

/***************MACROS******************/

#define BASE_16 "0123456789abcdef"
#define BASE_8 "01234567"
#define BASE_MAJ "0123456789abcef"

/***********PRINTS ALL BASES************/

void print_hexa(int nb);
void print_hexa_maj(int nb);
void print_octal(int nb);
void print_binary(int nb);
void print_pointer(int nb);

/****************BASICS PRINTS**********/

void my_putstr(char *str);
void my_put_nbr(unsigned int nb);
void my_putchar(char c);

/**************FLAG FLINDERZ*********/

void bases_checker(va_list list, char *str, int pos);
void hexa_traitemen(va_list list, char *str, int pos);
void char_traitement(va_list list, char *str, int pos, ...);
int nb_traitement(va_list list, char *str, int pos, ...);

#endif
