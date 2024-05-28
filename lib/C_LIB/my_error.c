/*
** EPITECH PROJECT, 2024
** lib_c
** File description:
** my_error
*/

#include "../../include/my.h"

int my_error(char *str)
{
    for (int i = 0; str[i]; i++)
        write(2, &str[i], 1);
    return FAILURE;
}

int verif_malloc(int nbr, ...)
{
    va_list ap;
    void *ptr;

    va_start(ap, nbr);
    for (int i = 0; i < nbr; i++) {
        ptr = va_arg(ap, void *);
        if (ptr == NULL)
            return FAILURE;
    }
    va_end(ap);
    return SUCCESS;
}
