/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** init
*/

#include "../include/my.h"

static int init_state(var_t m)
{
    m->state = malloc(sizeof(button_state_t));
    CHECK_MALLOC(m->state);
    STATE(tool) = PEN;
    STATE(color) = 1;
    STATE(shape) = CIRCLE;
    STATE(size) = false;
    STATE(file) = false;
    STATE(help) = false;
    STATE(file_gui) = NO_BUTTON;
    STATE(help_state) = NO_BUTTON;
    return SUCCESS;
}

static int init_window(var_t m)
{
    MODE = (sfVideoMode){1920, 1080, 32};
    WDW = sfRenderWindow_create(MODE, "My Paint", sfDefaultStyle , NULL);
    if (!WDW)
        return my_error("Error: Can't create the window\n");
    return SUCCESS;
}

static int init_shapes(var_t m)
{
    m->shapes = malloc(sizeof(shapes_t));
    CHECK_MALLOC(m->shapes);
    m->shapes->circle = sfCircleShape_create();
    m->shapes->rect = sfRectangleShape_create();

    CHECK_MALLOC(m->shapes->circle);
    CHECK_MALLOC(m->shapes->rect);
    m->shapes->size = 10;
    sfCircleShape_setRadius(m->shapes->circle, 10);
    sfCircleShape_setFillColor(m->shapes->circle, sfBlack);
    sfRectangleShape_setSize(m->shapes->rect, (V2F){10, 10});
    sfRectangleShape_setFillColor(m->shapes->rect, sfBlack);

    return SUCCESS;
}

int init_all(var_t m)
{
    CHECK_ERROR(init_window(m));
    CHECK_ERROR(init_state(m));
    CHECK_ERROR(init_shapes(m));
    CHECK_ERROR(init_gui(m));
    CHECK_ERROR(init_text(m));
    CHECK_ERROR(init_help(m));
    return SUCCESS;
}

