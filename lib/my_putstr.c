/*
** EPITECH PROJECT, 2024
** my_printf.c
** File description:
** my_putstr.c
*/


#include <stdio.h>
#include "../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
