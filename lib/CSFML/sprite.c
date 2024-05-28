/*
** EPITECH PROJECT, 2024
** CSFML LIB
** File description:
** sprite
*/

#include "../../include/lib_csfml.h"
#include "../../include/my.h"

sfSprite *create_sprite(char *file_name, sfVector2f pos)
{
    char *path = supercat(2, "assets/", file_name);
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfFloatRect spBounds;

    if (!texture){
        my_error(supercat(2, path, ": Can't create the texture\n"));
        return NULL;
    }
    if (!sprite){
        my_error("Error : Can't create the sprite\n");
        return NULL;
    }
    spBounds = sfSprite_getGlobalBounds(sprite);
    sfSprite_setOrigin(sprite, (V2F){spBounds.width / 2, spBounds.height / 2});
    set_position(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    free(path);
    return sprite;
}
