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


void execute_pipe_command(char **command, int input_fd,
    int output_fd, char **env)
{
    if (input_fd != -1) {
        dup2(input_fd, STDIN_FILENO);
        close(input_fd);
    }
    if (output_fd != -1) {
        dup2(output_fd, STDOUT_FILENO);
        close(output_fd);
    }
    interpret_command(command, env);
    exit(0);
}

int command_pipe(int pipe_fd[2], char **command_right, char **env)
{
    pid_t child2;

    child2 = fork();
    if (child2 == 0) {
        close(pipe_fd[1]);
        execute_pipe_command(command_right, pipe_fd[0], -1, env);
    }
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}

int pipe_redirect(char **args, int symbol_index, char **env)
{
    char **command_left = NULL;
    char **command_right = NULL;
    int pipe_fd[2];
    pid_t child1;

    args[symbol_index] = NULL;
    command_left = args;
    command_right = &args[symbol_index + 1];
    pipe(pipe_fd);
    child1 = fork();
    if (child1 == 0) {
        close(pipe_fd[0]);
        execute_pipe_command(command_left, -1, pipe_fd[1], env);
    }
    command_pipe(pipe_fd, command_right, env);
    return 0;
}
