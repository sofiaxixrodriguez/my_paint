/*
** EPITECH PROJECT, 2024
** lib c
** File description:
** lib_c
*/

#pragma once

    #define FAILURE 84
    #define SUCCESS 0
    #define CHECK_ERROR(f) if (f == FAILURE) return FAILURE
    #define CHECK_ERROR_MAIN(f) if (f == FAILURE) return end_main(FAILURE)
    #define CHECK_MALLOC(p) if (p == NULL) return FAILURE
    #define CHECK_MALLOCS(n, ...) if (verif_malloc(n, __VA_ARGS__) == FAILURE) \
                return FAILURE

int my_error(char *str);

int my_strcmp(char *str1, char *str2);

int my_strlen(char const *str);

void my_strcpy(char *dest, char *src);

int end_main(int return_value);

char *supercat(int nbr, ...);

int my_putstr(char *str);

int verif_malloc(int nbr, ...);

int is_alpha(char c);
