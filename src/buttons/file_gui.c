/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** tools
*/

#include "../../include/my.h"

static void change_file_gui_visibility(var_t m)
{
    sp_set_visible(C_SAVE, STATE(file_gui) == SAVE ? true : false);
    sp_set_visible(C_OPEN, STATE(file_gui) == LOAD ? true : false);
    sp_set_visible(C_NEW, STATE(file_gui) == NEW ? true : false);
    sp_set_visible(C_EXIT, STATE(file_gui) == EXIT ? true : false);
}

void file_gui_buttons(var_t m, sfVector2f mousePos)
{
    if (is_mouse_on_sprite(B_FILE_BTN, mousePos)){
        STATE(file) = !(STATE(file));
        sp_set_visible(C_FILE_GUI, STATE(file));
        STATE(file_gui) = NO_BUTTON;
    }
    if (!STATE(file))
        return;
    if (is_mouse_on_sprite(B_SAVE, mousePos))
        STATE(file_gui) = SAVE;
    if (is_mouse_on_sprite(B_OPEN, mousePos))
        STATE(file_gui) = LOAD;
    if (is_mouse_on_sprite(B_NEW, mousePos))
        STATE(file_gui) = NEW;
    if (is_mouse_on_sprite(B_EXIT, mousePos))
        STATE(file_gui) = EXIT;
    change_file_gui_visibility(m);
}
