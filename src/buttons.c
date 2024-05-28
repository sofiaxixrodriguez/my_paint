/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** buttons
*/

#include "../include/my.h"

void change_color_visibility(var_t m)
{
    sp_set_visible(C_COLOR1, STATE(color) == 1 ? true : false);
    if (STATE(color) == 1){
        sfRectangleShape_setSize(C_RECT1, (V2F){60, 60});
        sfRectangleShape_setPosition(C_RECT1, (V2F){1160, 75});
    }
}

void check_tools_buttons(var_t m, sfVector2f mousePos)
{
    tools_buttons(m, mousePos);
    shape_buttons(m, mousePos);
    file_gui_buttons(m, mousePos);
    color_buttons(m, mousePos);
    help_buttons(m, mousePos);
}
