/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** file_gui_action
*/

#include "../../include/my.h"

static void hide_file_gui(var_t m)
{
    STATE(file) = false;
    sp_set_visible(C_FILE_GUI, STATE(file));
    STATE(file_gui) = NO_BUTTON;
    sp_set_visible(C_SAVE, false);
    sp_set_visible(C_OPEN, false);
    sp_set_visible(C_NEW, false);
    sp_set_visible(C_EXIT, false);
}

static void draw_sprites_file_gui(var_t m, int file_gui)
{
    sfRenderWindow_clear(WDW, sfBlack);
    sfRenderWindow_drawSprite(WDW, GUI, NULL);
    if (file_gui == SAVE)
        sfRenderWindow_drawSprite(WDW, S_SAVE, NULL);
    if (file_gui == LOAD)
        sfRenderWindow_drawSprite(WDW, S_LOAD, NULL);
    if (file_gui == SAVE || file_gui == LOAD)
        sfRenderWindow_drawText(WDW, m->gui->buttons->save_text, NULL);
    sfRenderWindow_display(WDW);
}

static int get_event_file(var_t m, int file_gui)
{
    while (GET_EVENT(WDW, &EVENT)){
        if (EVENT.type == sfEvtClosed){
            STATE(file_gui) = EXIT;
            return 1;
        }
        if (file_gui == SAVE && save_gui(m))
            return 1;
        if (file_gui == LOAD && load_gui(m))
            return 1;
    }
    return 0;
}

int file_gui_action(var_t m)
{
    int file_state = STATE(file_gui);

    STATE(file) = false;
    STATE(file_gui) = NO_BUTTON;
    hide_file_gui(m);
    if (file_state == NEW){
        new_draw_space(m);
        return 1;
    }
    while (sfRenderWindow_isOpen(WDW)){
        draw_sprites_file_gui(m, file_state);
        if (get_event_file(m, file_state))
            break;
    }
    return 1;
}
