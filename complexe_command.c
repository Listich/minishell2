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

int is_complex_command(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        if (my_strncmp(args[i], "|", 1) == 0) {
            return i;
        }
        if (my_strncmp(args[i], "<", 1) == 0) {
            return i;
        }
        if (my_strncmp(args[i], ">", 1) == 0) {
            return i;
        }
        is_complex_command2(args, i);
    }
    return -1;
}

int is_complex_command2(char **args, int i)
{
    if (my_strncmp(args[i], ";", 1) == 0) {
            return i;
    }
    if (my_strncmp(args[i], "<<", 2) == 0) {
            return i;
    }
    if (my_strncmp(args[i], ">>", 2) == 0) {
            return i;
    }
    return -1;
}

int execute_complex_command(char **args, int symbol_index, char **env)
{
    int redirect_type = is_redirect_command(args, symbol_index);

    if (redirect_type != -1) {
        switch (redirect_type) {
        case OUTPUT:
            out_redirect(args, symbol_index, env);
            break;
        case INPUT:
            input_redirect(args, symbol_index, env);
            break;
        case APPEND:
            append_redirect(args, symbol_index, env);
            break;
        }
    } else if (my_strncmp(args[symbol_index], "|", 1) == 0) {
        pipe_redirect(args, symbol_index, env);
    }
    return 0;
}
