/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** shapes
*/

#include "../../include/my.h"

static void change_shape_visibility(var_t m)
{
    sp_set_visible(C_CIRCLE, STATE(shape) == CIRCLE ? true : false);
    sp_set_visible(C_RECT, STATE(shape) == RECTANGLE ? true : false);
}

void shape_buttons(var_t m, sfVector2f mousePos)
{
    if (is_mouse_on_sprite(B_CIRCLE, mousePos))
        STATE(shape) = CIRCLE;
    if (is_mouse_on_sprite(B_RECT, mousePos))
        STATE(shape) = RECTANGLE;
    if (is_mouse_on_sprite(B_LINE, mousePos))
        STATE(shape) = LINE;
    change_shape_visibility(m);
}
