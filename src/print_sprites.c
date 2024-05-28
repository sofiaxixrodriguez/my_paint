/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** print_sprites
*/

#include "../include/my.h"

static void draw_file_gui(var_t m)
{
    sfRenderWindow_drawSprite(WDW, C_FILE_GUI, NULL);
    sfRenderWindow_drawSprite(WDW, C_SAVE, NULL);
    sfRenderWindow_drawSprite(WDW, C_OPEN, NULL);
    sfRenderWindow_drawSprite(WDW, C_NEW, NULL);
    sfRenderWindow_drawSprite(WDW, C_EXIT, NULL);
    sfRenderWindow_drawRectangleShape(WDW, C_DROPDOWN, NULL);
    if (STATE(help)){
        sfRenderWindow_drawText(WDW, TXT_ABOUT, NULL);
        sfRenderWindow_drawText(WDW, TXT_HELP, NULL);
    }
}

static void draw_size_gui(var_t m)
{
    if (STATE(size)){
        sfRenderWindow_drawRectangleShape(WDW, C_SLIDER_GUI, NULL);
        sfRenderWindow_drawRectangleShape(WDW, C_SLIDER, NULL);
        sfRenderWindow_drawCircleShape(WDW, C_SLIDER_BTN, NULL);
    }
}

static void draw_buttons(var_t m)
{
    sfRenderWindow_drawSprite(WDW, C_ERASER, NULL);
    sfRenderWindow_drawSprite(WDW, C_BUCKET, NULL);
    sfRenderWindow_drawSprite(WDW, C_PEN, NULL);
    sfRenderWindow_drawSprite(WDW, C_PIP, NULL);
    if (STATE(tool) == 1)
        sfRenderWindow_drawSprite(WDW, C_COLOR1, NULL);
    sfRenderWindow_drawSprite(WDW, C_PALETTE, NULL);
    sfRenderWindow_drawSprite(WDW, C_SIZE, NULL);
    sfRenderWindow_drawRectangleShape(WDW, C_RECT1, NULL);
    sfRenderWindow_drawSprite(WDW, C_RECT, NULL);
    sfRenderWindow_drawSprite(WDW, C_CIRCLE, NULL);
}

void draw_gui(var_t m)
{
    sfRenderWindow_drawSprite(WDW, m->gui->gui_sprite, NULL);
    sfRenderWindow_drawSprite(WDW, m->gui->draw_zone_sprite, NULL);
    sfRenderWindow_drawRectangleShape(WDW, m->gui->draw_zone, NULL);
    sfRenderWindow_drawSprite(WDW, m->gui->draw_zone_sprite, NULL);
    sfRenderTexture_display(m->gui->draw_zone_texture);
}

void draw_tools_buttons(var_t m)
{
    draw_file_gui(m);
    check_hover(m, get_pxmousepos(WDW));
    draw_buttons(m);
    draw_size_gui(m);
    if (STATE(file_gui) != NO_BUTTON)
        file_gui_action(m);
    if (STATE(help_state) != NO_BUTTON)
        help_action(m);
}
