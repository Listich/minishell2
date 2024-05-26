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


char *allocate_and_fill_word(char *str, int *index)
{
    int cols = count_chars_until_space_or_newline(&str[*index]);
    char *word = malloc(sizeof(char) * (cols + 1));
    int col = 0;

    if (word == NULL) {
        return NULL;
    }
    while (col < cols) {
        word[col] = str[*index];
        col++;
        (*index)++;
    }
    word[col] = '\0';
    return word;
}

char **my_str_to_word_array(char *str)
{
    int index = 0;
    int row = 0;
    char **map = NULL;
    int spaces = 0;

    map = allocate_word_array(str, &spaces);
    if (map == NULL) {
        return NULL;
    }
    while (row < spaces) {
        map[row] = allocate_and_fill_word(str, &index);
        if (map[row] == NULL) {
            free_word_array(map);
            return NULL;
        }
        row++;
        index++;
    }
    map[row] = NULL;
    return map;
}

void free_word_array(char **words)
{
    int i = 0;

    if (words == NULL)
        return;
    while (words[i] != NULL) {
        free(words[i]);
        i++;
    }
    free(words);
}
