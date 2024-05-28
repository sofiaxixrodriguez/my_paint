/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my_strcmp
*/

#include "../../include/my.h"

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return 0;
    for (int i = 0; str1[i]; i++){
        if (str1[i] != str2[i])
            return 0;
    }
    return 1;
}
