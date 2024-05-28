/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** gui_bounds
*/

#include "../include/my.h"

static void set_invisible_bis(var_t m)
{
    sp_set_visible(C_EXIT, sfFalse);
    sp_set_visible(C_OPEN, sfFalse);
    sp_set_visible(C_RECT, sfFalse);
    sp_set_visible(C_CIRCLE, sfTrue);
    sp_set_visible(C_HELP, sfFalse);
}

static void set_invisible(var_t m)
{
    B_HELP = SP_GET_BOUNDS(C_HELP);
    sp_set_visible(C_COLOR1, true);
    sp_set_visible(C_ERASER, false);
    sp_set_visible(C_BUCKET, false);
    sp_set_visible(C_PEN, true);
    sp_set_visible(C_PIP, false);
    sp_set_visible(C_SIZE, false);
    sp_set_visible(C_FILE_GUI, false);
    sp_set_visible(C_NEW, sfFalse);
    sp_set_visible(C_SAVE, sfFalse);
    set_invisible_bis(m);
}

int init_bounds(var_t m)
{
    B_PEN = SP_GET_BOUNDS(C_PEN);
    B_BUCKET = SP_GET_BOUNDS(C_BUCKET);
    B_ERASER = SP_GET_BOUNDS(C_ERASER);
    B_PIP = SP_GET_BOUNDS(C_PIP);
    B_COLOR1 = SP_GET_BOUNDS(C_COLOR1);
    B_PALETTE = SP_GET_BOUNDS(C_PALETTE);
    B_SIZE = SP_GET_BOUNDS(C_SIZE);
    B_FILE_BTN = SP_GET_BOUNDS(C_FILE_BTN);
    B_SLIDER = sfCircleShape_getGlobalBounds(C_SLIDER_BTN);
    B_SAVE = SP_GET_BOUNDS(C_SAVE);
    B_OPEN = SP_GET_BOUNDS(C_OPEN);
    B_NEW = SP_GET_BOUNDS(C_NEW);
    B_EXIT = SP_GET_BOUNDS(C_EXIT);
    B_RECT = SP_GET_BOUNDS(C_RECT);
    B_CIRCLE = SP_GET_BOUNDS(C_CIRCLE);
    set_invisible(m);
    return SUCCESS;
}
