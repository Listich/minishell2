/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** Write a function that concatenates two strings.
*/

#include "../include/my.h"

char *my_strcat(char *dest, const char *src)
{
    char *rdest = NULL;

    if (dest == NULL || src == NULL) {
        return dest;
    }
    rdest = dest;
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest = *src;
        *dest++;
        *src++;
    }
    *dest = '\0';
    return rdest;
}
