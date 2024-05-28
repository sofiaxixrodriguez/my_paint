/*
** EPITECH PROJECT, 2024
** LIB C
** File description:
** my_putstr
*/

#include "../include/my.h"

int my_putstr(char *str)
{
    int i = my_strlen(str);

    write(1, str, i);
    return i;
}
