/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** draw
*/

#include "../include/my.h"

/*static void draw_line(var_t m, sfColor colors, int size)
{
    static sfVector2f pos1 = {0, 0};
    static int pressed = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) && pressed == 0){
        pressed = 1;
        pos1 = SHAPE(pos);
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft) && pressed == 1){
        sfVector2f delta = substract_vectors(SHAPE(pos), pos1);
        float length = sqrtf(delta.x * delta.x + delta.y * delta.y);
        sfRectangleShape* line = sfRectangleShape_create();
        sfRectangleShape_setSize(line, (sfVector2f){length, size});
        sfRectangleShape_setPosition(line, pos1);
        sfRectangleShape_setFillColor(line, colors);
        float angle = atan2f(delta.y, delta.x) * 180.f / PI;
        sfRectangleShape_setRotation(line, angle);
        sfRenderTexture_drawRectangleShape(T_DRAW, line, NULL);
        sfRenderTexture_display(T_DRAW);
        pressed = 0;
    }
}*/

static void change_draw_shape(var_t m, sfColor colors, sfVector2f mousePos)
{
    if (STATE(shape) == RECTANGLE && sfMouse_isButtonPressed(sfMouseLeft)){
        sfRectangleShape_setPosition(SHAPE(rect), SHAPE(pos));
        sfRenderTexture_drawRectangleShape(T_DRAW, SHAPE(rect), NULL);
        draw_straight_lines(RECTANGLE, SHAPE(pos), mousePos, m);
    }
    if (STATE(shape) == CIRCLE && sfMouse_isButtonPressed(sfMouseLeft)){
        sfCircleShape_setPosition(SHAPE(circle), SHAPE(pos));
        sfRenderTexture_drawCircleShape(T_DRAW, SHAPE(circle), NULL);
        draw_straight_lines(CIRCLE, mousePos, SHAPE(pos),m);
    }
    if (STATE(shape) == LINE){
        //draw_line(m, colors, SHAPE(size));
    }
}

static sfVector2f get_real_mouse_pos(var_t m, sfVector2f mousePos)
{
    sfVector2f posit = sfSprite_getPosition(S_DRAW);
    sfVector2f mouse_pos;

    mouse_pos.x = mousePos.x - (SHAPE(size) / 2) - posit.x;
    mouse_pos.y = mousePos.y - ((SHAPE(size)) / 2) - posit.y;
    if (STATE(shape) == LINE || STATE(tool) == BUCKET || STATE(tool) == PIP){
        mouse_pos.x += (SHAPE(size) / 2);
        mouse_pos.y += (SHAPE(size) / 2);
    }
    return mouse_pos;
}

static void special_tool_cases(var_t m)
{
        if (STATE(tool) == ERASER && sfMouse_isButtonPressed(sfMouseLeft)){
            sfCircleShape_setFillColor(SHAPE(circle), sfWhite);
            sfRectangleShape_setFillColor(SHAPE(rect), sfWhite);
        }
        if (STATE(tool) == PIP && sfMouse_isButtonPressed(sfMouseLeft)){
            pipette(m);
            return;
        }
}

void check_draw(var_t m, sfVector2f mousePos)
{
    sfColor colors;
    static sfVector2f pos_temp = {-1, -1};
    if (is_mouse_on_sprite(B_DRAW, mousePos)){
        colors = m->gui->color1;
        special_tool_cases(m);
        pos_temp = SHAPE(pos);
        SHAPE(pos) = get_real_mouse_pos(m, mousePos);
        if (STATE(tool) == BUCKET && sfMouse_isButtonPressed(sfMouseLeft)){
            fill_bucket(m, colors);
            return;
        }
        change_draw_shape(m, colors, pos_temp);
        sfCircleShape_setFillColor(SHAPE(circle), colors);
        sfRectangleShape_setFillColor(SHAPE(rect), colors);
        sfSprite_setTexture(S_DRAW, sfRenderTexture_getTexture(T_DRAW), sfTrue);
    }
}
