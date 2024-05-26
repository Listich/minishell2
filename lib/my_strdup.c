/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** write a function that allocates memory
*/

#include <stdio.h>
#include "../include/my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *cmp = (char *)malloc(sizeof(char)* my_strlen(src) + 1);

    if (!(cmp)) {
        return NULL;
    }
    while (*src) {
        cmp[i] = *src;
        i++;
        *src++;
    }
    cmp[i] = '\0';
    return cmp;
}
