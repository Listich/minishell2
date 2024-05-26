/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** Main file of minishell1
*/

#include <stdio.h>
#include "include/my.h"
#include "include/minishell.h"
#include <fcntl.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
        c == '\v' || c == '\f' || c == '\r');
}

char *trim_whitespace(char *str)
{
    char *end = NULL;

    while (is_space(*str)) {
        str++;
    }
    if (*str == '\0') {
        return str;
    }
    end = str + my_strlen(str) - 1;
    while (end > str && is_space(*end)) {
        end--;
    }
    end[1] = '\0';
    return str;
}

char **sanitize_input(char **args)
{
    char **clean_args = malloc(sizeof(char *) * 256);
    int index = 0;
    char *trimmed_arg = NULL;

    if (clean_args == NULL)
        return NULL;
    for (int i = 0; i < 256; i++)
        clean_args[i] = NULL;
    for (int i = 0; args[i] != NULL; i++) {
        trimmed_arg = trim_whitespace(args[i]);
        if (my_strlen(trimmed_arg) > 0) {
            clean_args[index] = my_strdup(trimmed_arg);
            if (clean_args[index] == NULL)
                return NULL;
            index++;
        }
    }
    clean_args[index] = NULL;
    return clean_args;
}
