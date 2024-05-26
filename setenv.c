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

char *create_varenv(const char *name, const char *value)
{
    char *variable = NULL;
    int value_length = 0;

    value_length = (value == NULL) ? 0 : my_strlen(value);
    variable = malloc((sizeof(char)*my_strlen(name)) +
        (sizeof(char) * value_length) + 2);
    my_strcpy(variable, name);
    my_strcat(variable, "=");
    if (value != NULL) {
        my_strcat(variable, value);
    }
    return variable;
}

int my_modify_env(const char *name, const char *value, char **env)
{
    int i = 0;

    while (env[i]) {
        if (my_strncmp(env[i], name, my_strlen(name)) == 0) {
            env[i] = create_varenv(name, value);
            return 1;
        }
        i++;
    }
    return 0;
}

int is_valid_setenv(const char *name)
{
    if (!is_char_alpha(name[0])) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return 0;
    }
    if (!is_str_alpha_numeric(name)) {
        my_printf("setenv: Variable name must ");
        my_printf("contain alphanumeric characters.");
        return 0;
    }
}

int my_setenv(const char *name, const char *value, char **env)
{
    int i = 0;
    char *variable = NULL;

    if (name == NULL && value == NULL) {
        my_env(env);
        return 0;
    }
    is_valid_setenv(name);
    if (my_modify_env(name, value, env)) {
        return 1;
    }
    for (; env[i] != NULL; i++) {
    }
    variable = create_varenv(name, value);
    env[i] = variable;
    env[i + 1] = NULL;
    return 1;
}
