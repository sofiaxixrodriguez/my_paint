/*
** EPITECH PROJECT, 2024
** CSFML Lib
** File description:
** lib_csfml
*/

#pragma once

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>
    #include <SFML/Network.h>

typedef sfVector2f V2F;
typedef sfIntRect IRECT;

    #define bool _Bool
    #define GET_EVENT sfRenderWindow_pollEvent
    #define SP_GET_BOUNDS sfSprite_getGlobalBounds
    #define RECT_GET_BOUNDS sfRectangleShape_getGlobalBounds

sfSprite *create_sprite(char *path, sfVector2f pos);

void set_position(sfSprite *sprite, sfVector2f pos);

sfRectangleShape *create_rect(sfColor color, sfIntRect rect);

int create_sprite_bounds(char *file_name, sfVector2f pos, sfSprite **sprite,
    sfFloatRect *spBounds);

void sp_set_visible(sfSprite *sprite, bool state);

sfVector2f get_pxmousepos(sfRenderWindow *window);

bool is_mouse_on_sprite(sfFloatRect sprite_rect, sfVector2f mouse_pos);

int change_state(int state, int button);

void rect_set_visible(sfRectangleShape *rect, bool state);

sfColor get_pixel(sfSprite *sprite, sfVector2f mousePos, sfFloatRect bounds);

void draw_if_hover(sfRenderWindow *window, sfFloatRect bounds,
    sfSprite *sprite, sfVector2f mousePos);

sfVector2f substract_vectors(sfVector2f v1, sfVector2f v2);
