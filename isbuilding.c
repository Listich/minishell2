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


int is_builtin(char **args, char **env)
{
    if (my_strcmp(args[0], "setenv") == 0) {
        my_setenv(args[1], args[2], env);
        return 1;
    }
    if (my_strcmp(args[0], "unsetenv") == 0) {
        my_unsetenv(args[1], env);
        return 1;
    }
    if (my_strcmp(args[0], "cd") == 0) {
        cd_command(args, env);
        return 1;
    }
    if (my_strcmp(args[0], "exit") == 0) {
        exit(0);
    }
    if (my_strcmp(args[0], "env") == 0) {
        my_env(env);
        return 1;
    }
    return 0;
}

void interpret_command(char **args, char **env)
{
    int symbol_index = -1;

    symbol_index = is_complex_command(args);
    if (symbol_index != -1) {
        execute_complex_command(args, symbol_index, env);
    } else {
        if (!is_builtin(args, env)) {
            execute_simple_command(args);
        }
    }
}
