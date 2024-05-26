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

void my_segfault(int waitstatus)
{
    if (WIFSIGNALED(waitstatus)) {
        if (WTERMSIG(waitstatus) == SIGFPE)
            write(2, "Floating exception", 18);
        if (WTERMSIG(waitstatus) == SIGSEGV)
            write(2, "Segmentation fault", 19);
        if (WCOREDUMP(waitstatus))
            write(2, " (core dumped)\n", 15);
        else
            write(2, "\n", 1);
    }
}
