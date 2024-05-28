/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** colors
*/

#include "../../include/my.h"

static void check_color_pick(var_t m, sfVector2f mousePos)
{
    sfColor color;

    if (is_mouse_on_sprite(B_PALETTE, mousePos)){
        color = get_pixel(C_PALETTE, mousePos, B_PALETTE);
        if (STATE(color) == 1){
            m->gui->color1 = color;
            sfRectangleShape_setFillColor(C_RECT1, color);
        }
        sfCircleShape_setFillColor(SHAPE(circle), color);
        sfRectangleShape_setFillColor(SHAPE(rect), color);
    }
}

void color_buttons(var_t m, sfVector2f mousePos)
{
    if (is_mouse_on_sprite(B_COLOR1, mousePos)){
        STATE(color) = 1;
        sfCircleShape_setFillColor(SHAPE(circle), m->gui->color1);
        sfRectangleShape_setFillColor(SHAPE(rect), m->gui->color1);
    }
    check_color_pick(m, mousePos);
}
