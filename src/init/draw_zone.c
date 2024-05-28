/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** draw_zone
*/

#include "../../include/my.h"

int init_drawable_zone(var_t m)
{
    sfRenderTexture *texture = sfRenderTexture_create(1500, 843, 0);
    CHECK_MALLOC(texture);
    sfRenderTexture_clear(texture, sfWhite);
    sfSprite *sprite = sfSprite_create();
    CHECK_MALLOC(sprite);
    sfSprite_setPosition(sprite, (V2F){200, 218});
    sfSprite_setTexture(sprite, sfRenderTexture_getTexture(texture), sfTrue);
    T_DRAW = texture;
    S_DRAW = sprite;
    sfRectangleShape* drawableZone = sfRectangleShape_create();
    CHECK_MALLOC(drawableZone);
    sfRectangleShape_setSize(drawableZone, (V2F){1500, 843});
    sfRectangleShape_setFillColor(drawableZone, sfWhite);
    sfRectangleShape_setOutlineColor(drawableZone, sfBlack);
    sfRectangleShape_setOutlineThickness(drawableZone, 1.0f);
    sfRectangleShape_setPosition(drawableZone, (V2F){200, 218});
    m->gui->draw_zone = drawableZone;
    B_DRAW = RECT_GET_BOUNDS(drawableZone);
    return SUCCESS;
}
