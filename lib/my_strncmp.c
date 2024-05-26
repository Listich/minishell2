/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** reproduce the behavior of the strncmp function
*/

int my_strncmp(const char *string1, const char *string2, int length)
{
    for (int i = 0; i < length; i++) {
        if (string1[i] != string2[i]) {
            return (string1[i] - string2[i]);
        }
        if (string1[i] == '\0' || string2[i] == '\0') {
            return 0;
        }
    }
    return 0;
}
