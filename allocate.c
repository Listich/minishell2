/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** Main file of minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "include/my.h"

int count_spaces(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            count++;
        i++;
    }
    count++;
    return count;
}

int count_chars_until_space_or_newline(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\n' && str[i] != '\0' && str[i] != ' ') {
        count++;
        i++;
    }
    return count;
}

char **allocate_word_array(char *str, int *spaces)
{
    char **map = NULL;

    *spaces = count_spaces(str);
    map = malloc(sizeof(char *) * (*spaces + 1));
    if (map == NULL) {
        free_word_array(map);
        return NULL;
    }
    return map;
}
