/*
** EPITECH PROJECT, 2024
** current
** File description:
** draw_straight_lines
*/

#include "../include/my.h"

void draw_straight_lines(int shape, sfVector2f pos1, sfVector2f pos2,
    var_t m)
{
    int dx = pos2.x - pos1.x;
    int dy = pos2.y - pos1.y;
    int steps = dx > dy ? dx : dy;
    steps *= (steps < 0) ? -1 : 1;
    for (int i = 0; i <= steps; i++) {
        float t = (float) i / (float) steps;
        sfVector2f pos = {pos1.x + t * dx, pos1.y + t * dy};
        if (shape == RECTANGLE){
            sfRectangleShape_setPosition(SHAPE(rect), pos);
            sfRenderTexture_drawRectangleShape(T_DRAW, SHAPE(rect), NULL);
        } else {
            sfCircleShape_setPosition(SHAPE(circle), pos);
            sfRenderTexture_drawCircleShape(T_DRAW, SHAPE(circle), NULL);
        }
    }
}
