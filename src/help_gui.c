/*
** EPITECH PROJECT, 2024
** current
** File description:
** help_gui
*/

#include "../include/my.h"

static void draw_sprites_file_gui(var_t m, int help_state)
{
    sfRenderWindow_clear(WDW, sfBlack);
    if (help_state == ABOUT)
        sfRenderWindow_drawSprite(WDW, S_ABOUT, NULL);
    if (help_state == HELP)
        sfRenderWindow_drawSprite(WDW, S_HELP, NULL);
    sfRenderWindow_display(WDW);
}

static int get_event_file(var_t m)
{
    while (GET_EVENT(WDW, &EVENT)){
        if (EVENT.type == sfEvtClosed){
            STATE(file_gui) = EXIT;
            return 1;
        }
        if (sfMouse_isButtonPressed(sfMouseLeft))
            return 1;
    }
    return 0;
}

int help_action(var_t m)
{
    int help_states = STATE(help_state);

    STATE(help) = false;
    STATE(help_state) = NO_BUTTON;
    rect_set_visible(C_DROPDOWN, false);
    while (sfRenderWindow_isOpen(WDW)){
        draw_sprites_file_gui(m, help_states);
        if (get_event_file(m))
            break;
    }
    return SUCCESS;
}
