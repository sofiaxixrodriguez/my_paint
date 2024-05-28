/*
** EPITECH PROJECT, 2024
** lib c
** File description:
** my_strcat
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *temp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    while (dest[i] != '\0'){
        temp[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        temp[i] = src[j];
        i++;
        j++;
    }
    temp[i] = '\0';
    return temp;
}

char *supercat(int nbr, ...)
{
    va_list ap;
    char *str = malloc(sizeof(char));
    char *temp;

    str[0] = '\0';
    va_start(ap, nbr);
    for (int i = 0; i < nbr; i++){
        temp = my_strcat(str, va_arg(ap, char *));
        free(str);
        str = temp;
    }
    va_end(ap);
    return str;
}
