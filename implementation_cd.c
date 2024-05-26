/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** Main file of minishell1
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>
#include <wait.h>
#include <sys/wait.h>
#include <unistd.h>
#include "include/minishell.h"
#include "include/my.h"

void cd_home(void)
{
    char oldpwd[128];
    char str[128] = "/home/";
    int i = 1;
    int k = 0;
    char *path = getcwd(oldpwd, sizeof(oldpwd));

    for (k = 0; str[k] != '\0'; k++);
    for (i = 1; path[i] != '/'; i++);
    i++;
    while (path[i] != '/') {
        str[k] = path[i];
        k++;
        i++;
    }
    chdir(str);
}

void cd_comd(char *line)
{
    int i = 0;
    int j = 0;
    char arg[128];
    int status = 0;

    while (line[i] != ' ' && line[i] != '\0') {
        arg[j] = line[i];
        i++;
        j++;
    }
    arg[j] = '\0';
    status = chdir(arg);
    if (status != 0) {
        perror(arg);
    }
    my_printf("[%s]\n", getcwd(NULL, 0));
}

void cd_command2(char **command)
{
    if (command[1] == NULL || my_strcmp(command[1], "~") == 0) {
        cd_home();
        return;
    }
    if (my_strcmp(command[1], "/") == 0) {
        chdir("/");
        return;
    } else {
        cd_comd(command[1]);
        return;
    }
}

void cd_command(char **args, char **env)
{
    char oldpwd[1024];

    if (my_strcmp(args[1], "..") == 0) {
        chdir("..");
        return;
    }
    if (my_strcmp(args[1], "-") == 0) {
        chdir(my_getenv(env, "PWD", oldpwd));
        return;
    }
    cd_command2(args);
}
