/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** Reproduce the behavior of the strcmp
*/
#include <stddef.h>

int my_strcmp(const char *str1, const char *str2)
{
    if (str1 == NULL || str2 == NULL) {
        return -1;
    }
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}
