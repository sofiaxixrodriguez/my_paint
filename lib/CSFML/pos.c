/*
** EPITECH PROJECT, 2024
** CSFML lib
** File description:
** pos
*/

#include "../../include/lib_csfml.h"
#include "../../include/my.h"

void set_position(sfSprite *sprite, sfVector2f pos)
{
    sfSprite_setPosition(sprite, pos);
}
