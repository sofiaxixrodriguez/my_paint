/*
** EPITECH PROJECT, 2024
** lib c
** File description:
** is_alpha
*/

#include "../include/my.h"

int is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c == '_' || c == '/' || c == '-' || c == '.')
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
