/*
** EPITECH PROJECT, 2024
** CSFML LIB
** File description:
** draw_hover
*/

#include "../include/my.h"

void draw_if_hover(sfRenderWindow *window, sfFloatRect bounds,
    sfSprite *sprite, sfVector2f mousePos)
{
    if (is_mouse_on_sprite(bounds, mousePos))
        sfRenderWindow_drawSprite(window, sprite, NULL);
}
