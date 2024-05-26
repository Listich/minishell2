/*
** EPITECH PROJECT, 2023
** B-PSU-100-TLS-1-1-myls-serena.kifoula
** File description:
** my_putchar.c
*/

#include <stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
