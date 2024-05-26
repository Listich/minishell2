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

int my_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_printf("%s\n", env[i]);
    }
    return 0;
}

int compared_env(const char *env, const char *name)
{
    int i = 0;

    while (env[i] != '=' && name[i] != '\0' && env[i] == name[i]) {
        i++;
    }
    if (env[i] == '=' && name[i] == '\0') {
        return i + 1;
    }
    return 0;
}

int extract_env_value(char **environ, int position,
    int equal_position, char *value)
{
    int k = 0;

    if (position == -1) {
        return -1;
    }
    while (environ[position][equal_position] != '\0') {
        value[k] = environ[position][equal_position];
        k++;
        equal_position++;
    }
    value[k] = '\0';
}

int my_getenv(char **environ, const char *name, char *value)
{
    int position = -1;
    int i = 0;
    int k = 0;
    int equal_position = -1;

    while (environ[i] != NULL) {
        equal_position = compared_env(environ[i], name);
        if (equal_position) {
            position = i;
            break;
        }
        i++;
    }
    extract_env_value(environ, position, equal_position, value);
    return 0;
}
