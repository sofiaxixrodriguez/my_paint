/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** bucket_tool
*/

#include "../include/my.h"

static bool is_colorequal(sfColor color1, sfColor color2)
{
    return (color1.r == color2.r && color1.g == color2.g && color1.b == color2.b
        && color1.a == color2.a);
}

static sfRectangleShape *create_bucket_rect(sfColor fillColor, int startX, int
    startY)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){1, 1});
    sfRectangleShape_setFillColor(rect, fillColor);
    sfRectangleShape_setPosition(rect, (sfVector2f){startX, startY});
    return rect;
}

static void fill_all(bucket_t bt)
{
    static int recursion = 0;
    while ((bt->fillIndex) > 0 && recursion++ < 500000) {
        sfVector2i pixel = bt->pixelsToFill[--(bt->fillIndex)];
        if (pixel.x < 0 || pixel.x >= bt->width || pixel.y < 0 ||
            pixel.y >= bt->height)
            continue;
        if (bt->filledPixels[pixel.y * bt->width + pixel.x])
            continue;
        sfColor crntColor = sfImage_getPixel(bt->image, pixel.x, pixel.y);
        if (!is_colorequal(crntColor, bt->color))
            continue;
        sfRectangleShape_setPosition(bt->rect, (sfVector2f){pixel.x, pixel.y});
        sfRenderTexture_drawRectangleShape(bt->T_DRAW, bt->rect, NULL);
        bt->filledPixels[pixel.y * bt->width + pixel.x] = 1;
        bt->pixelsToFill[bt->fillIndex++] = (sfVector2i){pixel.x + 1, pixel.y};
        bt->pixelsToFill[bt->fillIndex++] = (sfVector2i){pixel.x - 1, pixel.y};
        bt->pixelsToFill[bt->fillIndex++] = (sfVector2i){pixel.x, pixel.y + 1};
        bt->pixelsToFill[bt->fillIndex++] = (sfVector2i){pixel.x, pixel.y - 1};
    }
    recursion = 0;
}

void fill_bucket_func(var_t m, int startX, int startY, sfColor fillColor)
{
    bucket_t bt = malloc(sizeof(bucket_fill_t));
    const sfTexture* texture = sfRenderTexture_getTexture(T_DRAW);
    bt->image = sfTexture_copyToImage(texture);
    bt->rect = create_bucket_rect(fillColor, startX, startY);
    bt->width = sfImage_getSize(bt->image).x;
    bt->height = sfImage_getSize(bt->image).y;
    bt->color = sfImage_getPixel(bt->image, startX, startY);
    bt->filledPixels = malloc(bt->width * bt->height * sizeof(sfUint8));
    memset(bt->filledPixels, 0, bt->width * bt->height * sizeof(sfUint8));
    bt->pixelsToFill = malloc(bt->width * bt->height * sizeof(sfVector2i));
    memset(bt->pixelsToFill, 0, bt->width * bt->height * sizeof(sfVector2i));
    bt->fillIndex = 0;
    bt->pixelsToFill[bt->fillIndex++] = (sfVector2i){startX, startY};
    bt->m = m;
    fill_all(bt);
    free(bt->filledPixels);
    free(bt->pixelsToFill);
    free(bt);
}

void fill_bucket(var_t m, sfColor color)
{
    fill_bucket_func(m, SHAPE(pos).x, SHAPE(pos).y, color);
    sfRenderTexture_display(T_DRAW);
}
