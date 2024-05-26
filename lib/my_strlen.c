/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf.c
*/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdarg.h>
#include "../include/my.h"

int my_strlen(const char *str)
{
    size_t len = 0;

    if (str == NULL) {
        return 0;
    }
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
