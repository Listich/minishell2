/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-minishell2-serena.kifoula
** File description:
** alphanumeric.c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

bool is_char_alpha_numeric(char str)
{
    if (str >= 65 && str <= 90) {
        return true;
    }
    if (str >= 97 && str <= 122) {
        return true;
    }
    if (str >= 48 && str <= 57) {
        return true;
    }
    if (str == '_') {
        return true;
    }
    return false;
}

bool is_char_alpha(char str)
{
    if (str >= 65 && str <= 90) {
        return true;
    }
    if (str >= 97 && str <= 122) {
        return true;
    }
    if (str == '_') {
        return true;
    }
    return false;
}

bool is_str_alpha_numeric(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_char_alpha_numeric(str[i]) == false) {
            return false;
        }
    }
    return true;
}
