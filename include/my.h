/*
** EPITECH PROJECT, 2024
** my_printf.c
** File description:
** my.h
*/

#include <stdarg.h>

#ifndef MY_H
    #define MY_H
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <errno.h>
    #include <string.h>
    #include <time.h>
    #include <dirent.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <pwd.h>
    #include <grp.h>
    #include <sys/types.h>
    #include <stdlib.h>



void printchar(char c);
int put_nbr(int nb);
int put_unbr(unsigned int nb);
int printf_arg_num(char flag, va_list args);
int printf_arg_char2(char flag, va_list args);
int printf_arg_char(char flag, va_list args);
int printf_arg_base(char flag, va_list args);
int printf_arg(char flag, va_list args);
void printf_hex(long int b, bool uppercase);
void printf_octal(int o);
void printf_float(double a);
int my_printf(const char *format, ...);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
void my_putchar(char c);
int my_strcmp(const char *s1, const char *s2);
char *my_strcat(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
#endif /*MY_H_*/
