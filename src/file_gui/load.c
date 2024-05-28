/*
** EPITECH PROJECT, 2024
** current
** File description:
** load
*/

#include "../include/my.h"

static void load_file(var_t m, char *input)
{
    sfImage* image = sfImage_createFromFile(input);
    if (image == NULL)
        return;
    sfTexture* texture = sfTexture_createFromImage(image, NULL);
    sfSprite_setTexture(S_DRAW, texture, sfTrue);
    sfSprite_setPosition(S_DRAW, (V2F){0, 0});
    sfRenderTexture_drawSprite(T_DRAW, S_DRAW, NULL);
    sfRenderTexture_display(T_DRAW);
    sfSprite_setTexture(S_DRAW, sfRenderTexture_getTexture(T_DRAW), sfTrue);
    sfSprite_setPosition(S_DRAW, (V2F){200, 218});
}

int load_gui(var_t m)
{
    static char input[256] = "";
    static int index = 0;
    if (index >= 30 || (EVENT.type == sfEvtKeyPressed &&
        EVENT.key.code == sfKeyEnter)){
        load_file(m, input);
        input[0] = '\0';
        index = 0;
        return 1;
    }
    if (EVENT.type == sfEvtTextEntered && is_alpha(EVENT.key.code)){
        input[index++] = EVENT.key.code;
        input[index] = '\0';
        return 0;
    }
    if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyBackspace) {
        input[--index] = '\0';
    }
    sfText_setString(m->gui->buttons->save_text, input);
    return 0;
}
