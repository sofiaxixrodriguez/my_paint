/*
** EPITECH PROJECT, 2024
** current
** File description:
** save
*/

#include "../../include/my.h"

static void save_file(var_t m, char *input)
{
    char *path = supercat(3, "./saves/", input, ".jpg");
    const sfTexture* texture = sfRenderTexture_getTexture(T_DRAW);
    sfImage* image = sfTexture_copyToImage(texture);
    sfRenderTexture_getTexture(m->gui->draw_zone_texture);
    sfImage_saveToFile(image, path);
}

int save_gui(var_t m)
{
    static char input[40] = "";
    static int index = 0;
    if (index >= 30 || (EVENT.type == sfEvtKeyPressed &&
        EVENT.key.code == sfKeyEnter)){
        save_file(m, input);
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
