/*
** EPITECH PROJECT, 2024
** my paint
** File description:
** gui_sprites
*/

#include "../../include/my.h"

int init_hover(var_t m)
{
    H_PEN = create_sprite("h_brush.png", (V2F){532, 49});
    H_BUCKET = create_sprite("h_bucket.png", (V2F){434, 61});
    H_ERASER = create_sprite("h_eraser.png", (V2F){393, 114});
    H_PIP = create_sprite("h_pipette.png", (V2F){433, 114});
    H_COLOR1 = create_sprite("h_color1.jpg", (V2F){1114, 47});
    H_SIZE = create_sprite("h_size.png", (V2F){1018, 53});
    H_NEW = create_sprite("h_new.png", (V2F){3, 39});
    H_SAVE = create_sprite("h_save.png", (V2F){3, 174});
    H_EXIT = create_sprite("h_quit.png", (V2F){3, 241});
    H_OPEN = create_sprite("h_open.png", (V2F){3, 107});
    S_SAVE = create_sprite("save_file.png", (V2F){0, 0});
    S_LOAD = create_sprite("load_file.png", (V2F){0, 0});
    CHECK_MALLOCS(14,
        H_PEN, H_BUCKET, H_ERASER, H_PIP, H_COLOR1, H_SIZE,
        H_NEW, H_SAVE, H_EXIT, H_OPEN, S_SAVE, S_LOAD);
    return SUCCESS;
}

int init_buttons2(var_t m)
{
    C_NEW = create_sprite("h_new.png", (V2F){3, 39});
    C_SAVE = create_sprite("h_save.png", (V2F){3, 174});
    C_EXIT = create_sprite("h_quit.png", (V2F){3, 241});
    C_OPEN = create_sprite("h_open.png", (V2F){3, 107});
    C_HELP = create_sprite("help.jpg", (V2F){202, 1});
    C_CIRCLE = create_sprite("circle.png", (V2F){625, 55});
    C_RECT = create_sprite("rect.png", (V2F){739, 55});
    return SUCCESS;
}

int init_buttons(var_t m)
{
    C_PEN = create_sprite("brush.png", (V2F){532, 49});
    C_BUCKET = create_sprite("bucket.png", (V2F){434, 61});
    C_ERASER = create_sprite("eraser.png", (V2F){393, 114});
    C_PIP = create_sprite("pipette.png", (V2F){433, 114});
    C_COLOR1 = create_sprite("color1.jpg", (V2F){1114, 47});
    C_PALETTE = create_sprite("palette.png", (V2F){1258, 60});
    C_SIZE = create_sprite("size.png", (V2F){1018, 53});
    C_RECT1 = create_rect(sfBlack, (IRECT){1125, 55, 51, 51});
    C_FILE_BTN = create_sprite("palette2.jpg", (V2F){5, 1});
    C_FILE_GUI = create_sprite("gui_file.png", (V2F){3, 40});
    CHECK_ERROR(init_buttons2(m));
    CHECK_MALLOCS(17,
        C_PEN, C_BUCKET, C_ERASER, C_PIP, C_FILE_BTN, C_COLOR1, C_PALETTE,
        C_SIZE, C_RECT1, C_NEW, C_SAVE, C_EXIT, C_OPEN,
        C_HELP);
    return SUCCESS;
}
