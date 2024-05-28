/*
** EPITECH PROJECT, 2024
** current
** File description:
** help_btn
*/

#include "../../include/my.h"

void help_buttons(var_t m, sfVector2f mousePos)
{
    if (is_mouse_on_sprite(B_HELP, mousePos)){
        STATE(help) = !(STATE(help));
        rect_set_visible(C_DROPDOWN, STATE(help));
    }
    if (!STATE(help))
        return;
    if (is_mouse_on_sprite(B_ABOUT, mousePos))
        STATE(help_state) = ABOUT;
    if (is_mouse_on_sprite(B_HELP1, mousePos))
        STATE(help_state) = HELP;
}
