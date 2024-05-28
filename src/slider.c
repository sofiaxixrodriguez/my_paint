/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** slider
*/

#include "../include/my.h"

static void change_slider(var_t m, int x, int size)
{
    sfRectangleShape_setSize(SHAPE(rect), (sfVector2f){size, size});
    sfCircleShape_setRadius(SHAPE(circle), size / 2);
    sfCircleShape_setPosition(C_SLIDER_BTN, (sfVector2f){
        sfRectangleShape_getPosition(C_SLIDER).x + x, 218});
}

void check_size_slider(var_t m, sfVector2f mousePos)
{
    int x = mousePos.x - sfRectangleShape_getPosition(C_SLIDER).x;
    sfFloatRect bounds = sfCircleShape_getGlobalBounds(C_SLIDER_BTN);
    if (STATE(size) == 0)
        return;
    if (EVENT.type == sfEvtMouseButtonPressed && EVENT.mouseButton.button ==
        sfMouseLeft && is_mouse_on_sprite(bounds, mousePos)){
        m->shapes->size = (x / 4) + 1;
        change_slider(m, x, m->shapes->size);
    }
    if (EVENT.type == sfEvtMouseMoved &&
        sfMouse_isButtonPressed(sfMouseLeft) &&
        is_mouse_on_sprite(bounds, mousePos)){
        x = (x < 0) ? 0 : (x > 400) ? 400 : x;
        m->shapes->size = (x / 4) + 1;
        m->shapes->size = (m->shapes->size > 100) ? 100 : m->shapes->size;
        change_slider(m, x, m->shapes->size);
    }
}
