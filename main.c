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
#include <sys/wait.h>

void print_prompt(void)
{
    char wd[128];

    if (isatty(0)) {
        my_printf("[%s>]", getcwd(NULL, 0));
    }
}

void shift_left(char *str, int n)
{
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < my_strlen(str); i++) {
            str[i] = str[i + 1];
        }
    }
}

void execute_simple_command(char **args)
{
    char path[128] = "/bin/";
    int status = 0;
    pid_t child_id;

    my_strcat(path, args[0]);
    child_id = fork();
    if (child_id == -1) {
        exit(EXIT_FAILURE);
    }
    if (child_id == 0) {
        execve(path, args, NULL);
        my_printf("%s: Command not found.\n", args[0]);
        exit(EXIT_FAILURE);
    } else {
        waitpid(child_id, &status, 0);
        my_segfault(status);
    }
}

int free_all(char **clean_args, char **args)
{
    for (int i = 0; clean_args[i] != NULL; i++) {
        free(clean_args[i]);
    }
    free(clean_args);
    for (int i = 0; args[i] != NULL; i++) {
        free(args[i]);
    }
    free(args);
}

int main(int ac, char **av, char **env)
{
    char *user_input = NULL;
    char **args = NULL;
    char **clean_args = NULL;
    int len = 0;

    while (1) {
        print_prompt();
        if (getline(&user_input, &len, stdin) == -1) {
            break;
        }
        args = my_str_to_word_array(user_input);
        clean_args = sanitize_input(args);
        interpret_command(clean_args, env);
        free_all(clean_args, args);
    }
    return 0;
}
