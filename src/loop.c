/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** loop
*/

#include "../include/my.h"

static void click_analyse(var_t m)
{
    sfVector2f mousePos = get_pxmousepos(WDW);
    check_size_slider(m, mousePos);
    if ((STATE(size) == 0 && STATE(tool) == PEN) || STATE(tool) == ERASER ||
        STATE(tool) == BUCKET || STATE(tool) == PIP)
        check_draw(m, mousePos);
    if (EVENT.type == sfEvtMouseButtonPressed){
        check_tools_buttons(m, mousePos);
    }
    change_color_visibility(m);
}

void window_loop(var_t m)
{
    while (sfRenderWindow_isOpen(WDW)){
        if (GET_EVENT(WDW, &EVENT) && EVENT.type != sfEvtClosed)
            click_analyse(m);
        if (EVENT.type == sfEvtClosed || STATE(file_gui) == EXIT)
            sfRenderWindow_close(WDW);
        sfRenderWindow_clear(WDW, sfBlack);
        draw_gui(m);
        draw_tools_buttons(m);
        sfRenderWindow_display(WDW);
    }
    sfRenderWindow_close(WDW);
}
