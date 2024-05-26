/*
** EPITECH PROJECT, 2024
** my_printf.c
** File description:
** minishell.h
*/

#include <stdarg.h>

#ifndef MY_SHELL
    #define MY_SHELL


typedef struct minishell {
    char *command[16];
    char *tok;
    char *line;
} shell_t;

enum redirect_type {
    INPUT, /*<*/
    OUTPUT, /*>*/
    APPEND, /*>>*/
};
#endif /*MY_H_*/
