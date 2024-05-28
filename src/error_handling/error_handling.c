/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** error_handling
*/

#include "../../include/my.h"

static int check_args(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h")){
        my_putstr(
            "./my_paint\n\nDESCRIPTION\n\tRaster graphics editing program.\n");
        return SUCCESS;
    }
    if (ac != 1)
        return my_error("Error: invalid number of arguments.\n");
    return SUCCESS;
}

int error_handling(int ac, char **av, char **env)
{
    CHECK_ERROR(check_args(ac, av));
    return SUCCESS;
}
