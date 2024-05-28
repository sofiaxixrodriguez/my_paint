/*
** EPITECH PROJECT, 2024
** lib c
** File description:
** my_strcpy
*/

#include "../../include/my.h"

void my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
