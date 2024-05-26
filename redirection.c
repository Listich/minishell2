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

int is_redirect_command(char **args, int symbol_index)
{
    if (my_strncmp(args[symbol_index], ">", 1) == 0) {
        return OUTPUT;
    }
    if (my_strncmp(args[symbol_index], "<", 1) == 0) {
        return INPUT;
    }
    if (my_strncmp(args[symbol_index], ">>", 2) == 0) {
        return APPEND;
    }
    return -1;
}

int out_redirect(char **args, int symbol_index, char **env)
{
    char **command = NULL;
    char *filename = NULL;
    int fd = 0;
    pid_t child;

    args[symbol_index] = NULL;
    command = args;
    filename = args[symbol_index + 1];
    fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0777);
    child = fork();
    if (child == 0) {
        dup2(fd, STDOUT_FILENO);
        interpret_command(command, env);
        exit(0);
    } else {
        waitpid(child, NULL, 0);
    }
    return 0;
}

int input_redirect(char **args, int symbol_index, char **env)
{
    char **command = NULL;
    char *filename = NULL;
    int fd = 0;
    pid_t child;

    args[symbol_index] = NULL;
    command = args;
    filename = args[symbol_index + 1];
    fd = open(filename, O_RDONLY, 0777);
    child = fork();
    if (child == 0) {
        dup2(fd, STDOUT_FILENO);
        interpret_command(command, env);
        exit(0);
    } else {
        waitpid(child, NULL, 0);
    }
    return 0;
}

int append_redirect(char **args, int symbol_index, char **env)
{
    char **command = NULL;
    char *filename = NULL;
    int fd = 0;
    pid_t child;

    args[symbol_index] = NULL;
    command = args;
    filename = args[symbol_index + 1];
    fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0777);
    child = fork();
    if (child == 0) {
        dup2(fd, STDOUT_FILENO);
        interpret_command(command, env);
        exit(0);
    } else {
        waitpid(child, NULL, 0);
    }
    return 0;
}
