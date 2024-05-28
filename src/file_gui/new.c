/*
** EPITECH PROJECT, 2024
** current
** File description:
** new
*/

#include "../../include/my.h"

void new_draw_space(var_t m)
{
    sfRenderTexture_clear(m->gui->draw_zone_texture, sfWhite);
    sfSprite_setTexture(m->gui->draw_zone_sprite,
        sfRenderTexture_getTexture(m->gui->draw_zone_texture), sfTrue);
}
