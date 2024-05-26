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

int shift_unsetenv(char **env, int j, int i)
{
    for (j = i; env[j] != NULL; j++) {
        env[j] = env[j + 1];
    }
    env[j + 1] = NULL;
    return 1;
}

int my_unsetenv(const char *name, char **env)
{
    int i = 0;
    int j = 0;

    if (name == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        return 84;
    }
    while (env[i]) {
        if (my_strncmp(env[i], name, my_strlen(name)) == 0) {
            shift_unsetenv(env, j, i);
        }
        i++;
    }
    return 0;
}
