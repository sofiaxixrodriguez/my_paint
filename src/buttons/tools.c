/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** tools
*/

#include "../../include/my.h"

static void change_tool_visibility(var_t m, int tool_state)
{
    if (tool_state != STATE(tool)){
        sp_set_visible(C_ERASER, STATE(tool) == 1 ? true : false);
        sp_set_visible(C_BUCKET, STATE(tool) == 2 ? true : false);
        sp_set_visible(C_PEN, STATE(tool) == 3 ? true : false);
        sp_set_visible(C_PIP, STATE(tool) == 4 ? true : false);
    }
}

void tools_buttons(var_t m, sfVector2f mousePos)
{
    int tool_state = STATE(tool);
    if (is_mouse_on_sprite(B_ERASER, mousePos))
        STATE(tool) = change_state(tool_state, ERASER);
    if (is_mouse_on_sprite(B_BUCKET, mousePos))
        STATE(tool) = change_state(tool_state, BUCKET);
    if (is_mouse_on_sprite(B_PEN, mousePos))
        STATE(tool) = change_state(tool_state, PEN);
    if (is_mouse_on_sprite(B_PIP, mousePos))
        STATE(tool) = change_state(tool_state, PIP);
    if (is_mouse_on_sprite(B_SIZE, mousePos)){
        STATE(size) = !(STATE(size));
        sp_set_visible(C_SIZE, STATE(size));
    }
    change_tool_visibility(m, tool_state);
}
