/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** gui
*/

#include "../../include/my.h"

static int init_slider(var_t m)
{
    C_SLIDER = sfRectangleShape_create();
    C_SLIDER_BTN = sfCircleShape_create();
    C_SLIDER_GUI = sfRectangleShape_create();
    CHECK_MALLOC(C_SLIDER);
    CHECK_MALLOC(C_SLIDER_BTN);
    CHECK_MALLOC(C_SLIDER_GUI);
    sfRectangleShape_setSize(C_SLIDER, (V2F){ 400, 10 });
    sfRectangleShape_setFillColor(C_SLIDER, sfWhite);
    sfRectangleShape_setPosition(C_SLIDER, (V2F){ 865, 215 });
    sfRectangleShape_setSize(C_SLIDER_GUI, (V2F){500, 200});
    sfRectangleShape_setFillColor(C_SLIDER_GUI, (sfColor){128, 128, 128, 255});
    sfRectangleShape_setPosition(C_SLIDER_GUI, (V2F){ 817, 165 });
    sfCircleShape_setRadius(C_SLIDER_BTN, 20);
    sfCircleShape_setFillColor(C_SLIDER_BTN, sfRed);
    sfCircleShape_setOrigin(C_SLIDER_BTN, (V2F){ 20, 20 });
    sfCircleShape_setPosition(C_SLIDER_BTN, (V2F){ 905, 218 });
    return SUCCESS;
}

int init_gui(var_t m)
{
    m->gui = malloc(sizeof(struct my_gui));
    CHECK_MALLOC(m->gui);
    m->gui->color1 = sfBlack;

    m->gui->buttons = malloc(sizeof(struct gui_button));
    m->gui->bounds = malloc(sizeof(struct gui_bounds));
    m->gui->hover = malloc(sizeof(struct gui_hover));
    CHECK_MALLOC(m->gui->buttons);
    CHECK_MALLOC(m->gui->bounds);
    CHECK_MALLOC(m->gui->hover);
    CHECK_ERROR(init_slider(m));
    CHECK_ERROR(init_buttons(m));
    CHECK_ERROR(init_bounds(m));
    CHECK_ERROR(init_hover(m));

    m->gui->gui_sprite = create_sprite("paint.png", (V2F){0, 0});
    CHECK_MALLOC(m->gui->gui_sprite);
    CHECK_ERROR(init_drawable_zone(m));
    return SUCCESS;
}
