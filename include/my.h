/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** my
*/

    #pragma once

    #include "garbage.h"
    #define malloc my_malloc
    #define free my_free

    #include "lib_c.h"
    #include "lib_csfml.h"

    #define _GNU_SOURCE
    #include <stdio.h>
    #include <errno.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <time.h>
    #include <math.h>
    #include <signal.h>
    #include <sys/wait.h>
    #include <string.h>

#define H_ERASER m->gui->hover->eraser
#define H_BUCKET m->gui->hover->bucket
#define H_PEN m->gui->hover->pen
#define H_PIP m->gui->hover->pip
#define H_COLOR1 m->gui->hover->color1
#define H_SIZE m->gui->hover->size
#define H_NEW m->gui->hover->new
#define H_OPEN m->gui->hover->load
#define H_SAVE m->gui->hover->save
#define H_EXIT m->gui->hover->exit

#define C_ERASER m->gui->buttons->eraser
#define C_BUCKET m->gui->buttons->bucket
#define C_PEN m->gui->buttons->pen
#define C_PIP m->gui->buttons->pip
#define C_COLOR1 m->gui->buttons->color1
#define C_PALETTE m->gui->buttons->palette
#define C_SLIDER m->gui->buttons->slider
#define C_SLIDER_BTN m->gui->buttons->slider_btn
#define C_RECT1 m->gui->buttons->rect1
#define C_SIZE m->gui->buttons->size
#define C_FILE_GUI m->gui->buttons->file_gui
#define C_FILE_BTN m->gui->buttons->file_btn
#define C_SLIDER_GUI m->gui->buttons->slider_gui
#define C_NEW m->gui->buttons->new
#define C_OPEN m->gui->buttons->load
#define C_SAVE m->gui->buttons->save
#define C_EXIT m->gui->buttons->exit
#define C_CIRCLE m->gui->buttons->circle
#define C_RECT m->gui->buttons->rect
#define C_HELP m->gui->buttons->help
#define C_DROPDOWN m->gui->buttons->dropdown
#define S_HELP m->gui->buttons->help_s
#define S_ABOUT m->gui->buttons->about_s

#define B_ERASER m->gui->bounds->eraser
#define B_BUCKET m->gui->bounds->bucket
#define B_PEN m->gui->bounds->pen
#define B_PIP m->gui->bounds->pip
#define B_COLOR1 m->gui->bounds->color1
#define B_PALETTE m->gui->bounds->palette
#define B_SIZE m->gui->bounds->size
#define B_FILE_BTN m->gui->bounds->file_btn
#define B_FILE_GUI m->gui->bounds->file_gui
#define B_SLIDER m->gui->bounds->slider
#define B_SLIDER_GUI m->gui->bounds->slider_gui
#define B_SAVE m->gui->bounds->save
#define B_OPEN m->gui->bounds->load
#define B_EXIT m->gui->bounds->exit
#define B_NEW m->gui->bounds->new
#define B_COLOR1 m->gui->bounds->color1
#define B_CIRCLE m->gui->bounds->circle
#define B_RECT m->gui->bounds->rect
#define B_LINE m->gui->bounds->line
#define B_HELP m->gui->bounds->help
#define B_ABOUT m->gui->bounds->about
#define B_HELP1 m->gui->bounds->help1

#define B_DRAW m->gui->draw_zone_bounds
#define T_DRAW m->gui->draw_zone_texture
#define S_DRAW m->gui->draw_zone_sprite

#define WDW m->window
#define EVENT m->evt
#define MODE m->mode
#define SHAPE_SIZE m->shape_size
#define SHAPE_POS m->shape_pos
#define STATE(x) m->state->x
#define SHAPE(x) m->shapes->x
#define GUI m->gui->gui_sprite
#define S_SAVE m->gui->buttons->save_screen
#define S_LOAD m->gui->buttons->load_screen
#define TXT_HELP m->gui->buttons->help_text
#define TXT_ABOUT m->gui->buttons->about_text

enum tools_state{
    NO_TOOL = -1,
    ERASER = 1,
    BUCKET,
    PEN,
    PIP,
};

enum files_gui_state{
    NO_BUTTON = -1,
    SAVE = 1,
    LOAD,
    NEW,
    EXIT
};

enum shapes_state{
    CIRCLE = 1,
    RECTANGLE,
    LINE
};

enum help_state{
    HELP = 1,
    ABOUT
};

struct gui_hover{
    sfSprite *pen;
    sfSprite *eraser;
    sfSprite *bucket;
    sfSprite *pip;
    sfSprite *color1;
    sfSprite *size;
    sfSprite *new;
    sfSprite *save;
    sfSprite *load;
    sfSprite *exit;
};
typedef struct gui_hover gui_hover_t;
typedef gui_hover_t *hover_t;

struct gui_button{
    sfSprite *pen;
    sfSprite *eraser;
    sfSprite *bucket;
    sfSprite *pip;
    sfSprite *color1;
    sfSprite *size;
    sfSprite *file_gui;
    sfSprite *file_btn;
    sfRectangleShape *rect1;
    sfRectangleShape *rect2;
    sfSprite *palette;
    sfRectangleShape* slider;
    sfCircleShape* slider_btn;
    sfRectangleShape *slider_gui;
    sfSprite *new;
    sfSprite *save;
    sfSprite *load;
    sfSprite *exit;
    sfSprite *save_screen;
    sfSprite *load_screen;
    sfText *save_text;
    sfSprite *circle;
    sfSprite *rect;
    sfSprite *line;
    sfSprite *help;
    sfRectangleShape *about;
    sfText *about_text;
    sfRectangleShape *help_button;
    sfText *help_text;
    sfRectangleShape *dropdown;
    sfSprite *about_s;
    sfSprite *help_s;
};
typedef struct gui_button gui_button_t;
typedef gui_button_t *buttons_t;

struct gui_bounds{
    sfFloatRect pen;
    sfFloatRect eraser;
    sfFloatRect bucket;
    sfFloatRect pip;
    sfFloatRect color1;
    sfFloatRect palette;
    sfFloatRect size;
    sfFloatRect file_btn;
    sfFloatRect file_gui;
    sfFloatRect slider;
    sfFloatRect slider_gui;
    sfFloatRect shape1;
    sfFloatRect shape2;
    sfFloatRect shape3;
    sfFloatRect save;
    sfFloatRect load;
    sfFloatRect exit;
    sfFloatRect new;
    sfFloatRect circle;
    sfFloatRect rect;
    sfFloatRect line;
    sfFloatRect help;
    sfFloatRect about;
    sfFloatRect help1;
};
typedef struct gui_bounds gui_bounds_t;
typedef gui_bounds_t *bounds_t;

struct button_state{
    int shape;
    int tool;
    int color;
    int file_gui;
    bool size;
    bool file;
    bool help;
    int help_state;
};
typedef struct button_state button_state_t;
typedef button_state_t *state_t;

struct shapes{
    sfCircleShape *circle;
    sfRectangleShape *rect;
    sfVector2f pos;
    int size;
    sfVector2f line_pos1;
    sfVector2f line_pos2;
};
typedef struct shapes shapes_t;
typedef shapes_t *shape_t;

struct my_gui{
    buttons_t buttons;
    bounds_t bounds;
    hover_t hover;
    sfSprite *gui_sprite;
    sfRenderTexture *draw_zone_texture;
    sfSprite *draw_zone_sprite;
    sfRectangleShape *draw_zone;
    sfFloatRect draw_zone_bounds;
    sfColor color1;
    sfFont *font;
};
typedef struct my_gui my_gui_t;
typedef my_gui_t *gui_t;

struct my_variables{

    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent evt;
    gui_t gui;
    state_t state;
    shape_t shapes;

};
typedef struct my_variables my_var_t;
typedef my_var_t *var_t;

struct bucket_fill{
    var_t m;
    sfImage *image;
    sfRectangleShape *rect;
    int width;
    int height;
    sfColor color;
    sfUint8 *filledPixels;
    sfVector2i *pixelsToFill;
    int fillIndex;
};
typedef struct bucket_fill bucket_fill_t;
typedef bucket_fill_t *bucket_t;

int error_handling(int ac, char **av, char **env);

int init_all(var_t m);

void change_tools_visibility(var_t m);

void check_tools_buttons(var_t m, sfVector2f mousePos);

void draw_tools_buttons(var_t m);

void window_loop(var_t m);

int init_gui(var_t m);

void change_color_visibility(var_t m);

void check_hover(var_t m, sfVector2f mousePos);

void check_size_slider(var_t m, sfVector2f mousePos);


int init_drawable_zone(var_t m);

int init_bounds(var_t m);

int init_buttons(var_t m);

void tools_buttons(var_t m, sfVector2f mousePos);

void shape_buttons(var_t m, sfVector2f mousePos);

void check_hover(var_t m, sfVector2f mousePos);

void file_gui_buttons(var_t m, sfVector2f mousePos);

void color_buttons(var_t m, sfVector2f mousePos);

void check_draw(var_t m, sfVector2f mousePos);

void draw_gui(var_t m);

int init_hover(var_t m);

int init_text(var_t m);

void new_draw_space(var_t m);

int save_gui(var_t m);

int load_gui(var_t m);

int file_gui_action(var_t m);

int help_action(var_t m);

void fill_bucket(var_t m, sfColor color);

void pipette(var_t m);

void help_buttons(var_t m, sfVector2f mousePos);

int init_help(var_t m);

void draw_straight_lines(int shape, sfVector2f pos1, sfVector2f pos2,
    var_t m);
