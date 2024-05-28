/*
** EPITECH PROJECT, 2024
** CSFML LIB
** File description:
** rectangle
*/

#include "../../include/lib_csfml.h"
#include "../../include/my.h"

sfRectangleShape *create_rect(sfColor color, sfIntRect rect)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    if (!rectangle){
        my_error("Error : Can't create the rectangle\n");
        return NULL;
    }
    sfRectangleShape_setFillColor(rectangle, color);
    sfRectangleShape_setSize(rectangle, (V2F){rect.width, rect.height});
    sfRectangleShape_setPosition(rectangle, (V2F){rect.left, rect.top});
    g_insert_end(rectangle, *get_llist());
    return rectangle;
}
