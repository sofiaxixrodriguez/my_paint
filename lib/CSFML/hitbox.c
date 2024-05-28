/*
** EPITECH PROJECT, 2024
** CSFML LIB
** File description:
** hitbox
*/

#include "../include/my.h"

bool is_mouse_on_sprite(sfFloatRect sprite_rect, sfVector2f mouse_pos)
{
    if (sfFloatRect_contains(&sprite_rect, mouse_pos.x, mouse_pos.y))
        return true;
    return false;
}

int change_state(int state, int button)
{
    if (state == button)
        return -1;
    return button;
}
