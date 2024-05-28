/*
** EPITECH PROJECT, 2024
** current
** File description:
** help
*/

#include "../../include/my.h"

static int change_help_visibility(var_t m)
{
    sfText_setString(TXT_ABOUT, "ABOUT");
    sfText_setFillColor(TXT_ABOUT, sfBlack);
    sfText_setCharacterSize(TXT_ABOUT, 20);
    sfText_setPosition(TXT_ABOUT, (sfVector2f){203, 80});
    B_ABOUT = sfText_getGlobalBounds(TXT_ABOUT);
    B_HELP1 = sfText_getGlobalBounds(TXT_HELP);
    rect_set_visible(C_DROPDOWN, false);
    sfRectangleShape *btn1 = sfRectangleShape_create();
    CHECK_MALLOC(btn1);
    sfRectangleShape *btn2 = sfRectangleShape_create();
    CHECK_MALLOC(btn2);
    sfRectangleShape_setPosition(btn1, (V2F){203, 40});
    sfRectangleShape_setPosition(btn2, (V2F){203, 80});
    sfRectangleShape_setSize(btn1, (V2F){102, 40});
    sfRectangleShape_setSize(btn2, (V2F){102, 40});
    B_ABOUT = sfRectangleShape_getGlobalBounds(btn2);
    B_HELP1 = sfRectangleShape_getGlobalBounds(btn1);
    return SUCCESS;
}

int init_help(var_t m)
{
    S_ABOUT = create_sprite("about.png", (V2F){0, 0});
    CHECK_MALLOC(S_ABOUT);
    S_HELP = create_sprite("help_gui.png", (V2F){0, 0});
    CHECK_MALLOC(S_HELP);
    C_DROPDOWN = sfRectangleShape_create();
    CHECK_MALLOC(C_DROPDOWN);
    sfRectangleShape_setFillColor(C_DROPDOWN, sfWhite);
    sfRectangleShape_setSize(C_DROPDOWN, (sfVector2f){102, 80});
    sfRectangleShape_setPosition(C_DROPDOWN, (sfVector2f){203, 40});
    TXT_HELP = sfText_create();
    CHECK_MALLOC(TXT_HELP);
    sfText_setFont(TXT_HELP, m->gui->font);
    sfText_setString(TXT_HELP, "HELP");
    sfText_setCharacterSize(TXT_HELP, 20);
    sfText_setFillColor(TXT_HELP, sfBlack);
    sfText_setPosition(TXT_HELP, (sfVector2f){203, 40});
    TXT_ABOUT = sfText_create();
    CHECK_MALLOC(TXT_ABOUT);
    sfText_setFont(TXT_ABOUT, m->gui->font);
    return change_help_visibility(m);
}
